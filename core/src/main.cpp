#include "imgui.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_sdl2.h"
#include <SDL.h>
#include <SDL_opengl.h>
#include <cstdio>

#include <channel.hpp>
#include <implot.h>
#include <memory>
#include <oscilloscope.hpp>
#include <trigger.hpp>
#include <ui.hpp>
#include <usb.hpp>

// ---------------------------------------------------------------------------
// SDL / ImGui lifecycle
// ---------------------------------------------------------------------------

static const char *GLSL_VERSION = "#version 130";

static SDL_Window *initSDL() {
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0) {
    printf("SDL error: %s\n", SDL_GetError());
    return nullptr;
  }

  SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
  SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

  SDL_WindowFlags flags =
      (SDL_WindowFlags)(SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE |
                        SDL_WINDOW_ALLOW_HIGHDPI);
  return SDL_CreateWindow("Scoped", SDL_WINDOWPOS_CENTERED,
                          SDL_WINDOWPOS_CENTERED, 1280, 800, flags);
}

static SDL_GLContext initOpenGL(SDL_Window *window) {
  SDL_GLContext ctx = SDL_GL_CreateContext(window);
  SDL_GL_MakeCurrent(window, ctx);
  SDL_GL_SetSwapInterval(1);
  return ctx;
}

static void initImGui(SDL_Window *window, SDL_GLContext gl_context) {
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImPlot::CreateContext();

  ImGuiIO &io = ImGui::GetIO();
  io.ConfigFlags |=
      ImGuiConfigFlags_NavEnableKeyboard | ImGuiConfigFlags_DockingEnable;

  ImGui::StyleColorsDark();
  ImGui_ImplSDL2_InitForOpenGL(window, gl_context);
  ImGui_ImplOpenGL3_Init(GLSL_VERSION);
}

static void shutdownImGui() {
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplSDL2_Shutdown();
  ImPlot::DestroyContext();
  ImGui::DestroyContext();
}

static void shutdownSDL(SDL_Window *window, SDL_GLContext gl_context) {
  SDL_GL_DeleteContext(gl_context);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

// ---------------------------------------------------------------------------
// Main
// ---------------------------------------------------------------------------

int main(int, char **) {
  SDL_Window *window = initSDL();
  if (!window)
    return 1;

  SDL_GLContext gl_context = initOpenGL(window);
  initImGui(window, gl_context);

  Scoped::Oscilloscope osc;

  auto ch1 = std::make_shared<Scoped::Channel<uint8_t>>("CH1", 16384 * 4, 2048);
  osc.addChannel(ch1);

  auto trigger = std::make_unique<Scoped::EdgeTrigger>(16384, 128.0f);
  osc.setTrigger(std::move(trigger));
  osc.setTriggerSource(0);

  // UI created after OpenGL is ready, destroyed before shutdown
  Scoped::OscilloscopeUI ui(1280, 720);
  Scoped::setupChannelColormap(ImVec4(0, 1, 1, 1));

  ImGuiIO &io = ImGui::GetIO();

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

    if (!osc.getUSB().isConnected()) {
      for (int i = 0; i < 16; ++i)
        ch1->getBuffer().fillTestSineWave();
    }

    osc.update();
    ui.render(osc);

    ImGui::Render();
    glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    SDL_GL_SwapWindow(window);
  }

  // UI destroyed here (before GL context teardown) — clean lifetime
  shutdownImGui();
  shutdownSDL(window, gl_context);

  return 0;
}
