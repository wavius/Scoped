cmake_minimum_required(VERSION 3.15)
project(Scoped VERSION 0.1.0 LANGUAGES CXX)

# 1. Set C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 2. Find Dependencies
find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)

# 3. List the Source Files (EXPLICIT FILES ONLY)
set(SOURCES
    # Local source files
    core/src/main.cpp
    core/src/signalbuffer.cpp

# External source files
    extern/imgui/imgui.cpp
    extern/imgui/imgui_draw.cpp
    extern/imgui/imgui_widgets.cpp
    extern/imgui/imgui_tables.cpp
    extern/imgui/backends/imgui_impl_sdl2.cpp
    extern/imgui/backends/imgui_impl_opengl3.cpp
    extern/implot/implot.cpp
    extern/implot/implot_items.cpp
    extern/imgui/imgui_demo.cpp
)

# 4. Create the Executable
add_executable(Scoped ${SOURCES})

# 5. Define Include Directories
# target_include_directories is preferred over include_directories
target_include_directories(Scoped PRIVATE
    core/src
    core/inc
    extern/imgui
    extern/imgui/backends
    extern/implot
)

# 6. Link Libraries
target_link_libraries(Scoped PRIVATE
    SDL2::SDL2
    OpenGL::GL
    dl
)
