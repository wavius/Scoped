#include "imgui.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_sdl2.h"
#include <SDL.h>
#include <SDL_opengl.h>
#include <cstdio>

#include <circularbuffer.hpp>
#include <displayframe.hpp>
#include <implot.h>
#include <intensitymap.hpp>
#include <trigger.hpp>
#include <ui.hpp>

int main(int, char **) {
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0) {
    printf("Error: %s\n", SDL_GetError());
    return 1;
  }

  // GL 3.0 + GLSL 130
  const char *glsl_version = "#version 130";
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
  SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

  SDL_WindowFlags window_flags =
      (SDL_WindowFlags)(SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE |
                        SDL_WINDOW_ALLOW_HIGHDPI);
  SDL_Window *window =
      SDL_CreateWindow("Scoped Oscilloscope", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, 1280, 800, window_flags);

  SDL_GLContext gl_context = SDL_GL_CreateContext(window);
  SDL_GL_MakeCurrent(window, gl_context);
  SDL_GL_SetSwapInterval(1);

  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImPlot::CreateContext();

  ImGuiIO &io = ImGui::GetIO();
  io.ConfigFlags |=
      ImGuiConfigFlags_NavEnableKeyboard | ImGuiConfigFlags_DockingEnable;

  ImGui::StyleColorsDark();
  ImGui_ImplSDL2_InitForOpenGL(window, gl_context);
  ImGui_ImplOpenGL3_Init(glsl_version);

  // Core pipeline objects
  Scoped::CircularBuffer ring_buffer(8192);
  Scoped::Trigger trigger(1024, 128);
  Scoped::DisplayFrame frame(1024);
  Scoped::IntensityMap intensity_map(1024, 512);
  Scoped::setupChannelColormap(ImVec4(0, 1, 1, 1));

  bool running = true;
  while (running) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      ImGui_ImplSDL2_ProcessEvent(&event);
      if (event.type == SDL_QUIT)
        running = false;
    }

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL2_NewFrame();
    ImGui::NewFrame();

    // Simulate incoming hardware data
    ring_buffer.fillTestSineWave();

    // Trigger controls
    ImGui::Begin("Scope Controls");

    static int trigger_level = 128;
    static int edge_selection = 0;
    const char *edge_options[] = {"Rising Edge", "Falling Edge"};

    ImGui::SliderInt("Trigger Level", &trigger_level, 0, 255);
    ImGui::Combo("Trigger Edge", &edge_selection, edge_options, 2);

    trigger.setThreshold(static_cast<uint8_t>(trigger_level));
    trigger.setType(edge_selection == 0 ? Scoped::TriggerType::RISING_EDGE
                                        : Scoped::TriggerType::FALLING_EDGE);
    ImGui::End();

    // Signal processing pipeline
    if (trigger.processStream(ring_buffer)) {
      frame.copyFrom(trigger.getOutput());
      intensity_map.clear();
      intensity_map.processFrame(frame);
    }

    // Oscilloscope display
    ImGui::Begin("Oscilloscope");
    Scoped::renderIntensityMap(intensity_map);
    ImGui::End();

    ImGui::Render();
    glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    SDL_GL_SwapWindow(window);
  }

  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplSDL2_Shutdown();
  ImPlot::DestroyContext();
  ImGui::DestroyContext();

  SDL_GL_DeleteContext(gl_context);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
