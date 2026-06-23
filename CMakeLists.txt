cmake_minimum_required(VERSION 3.15)
project(Scoped VERSION 0.1.0 LANGUAGES CXX)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Build Type and Optimization Flags
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# Set global flags for Release builds
if(MSVC)
  # Windows specific optimizations
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /O2 /Oi /Ot /GL")
else()
  # Fedora/GCC specific optimizations
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -march=native -ffast-math")
endif()

# Project Settings
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Find Dependencies
find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(LIBUSB REQUIRED libusb-1.0)

# List the Source Files
set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/core/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/core/src/ui/intensitymap.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/core/src/ui/ui.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/core/src/ui/ui_channel.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/core/src/ui/ui_fft.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/core/src/ui/ui_math.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/core/src/ui/ui_filter.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/core/src/ui/ui_measurement.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/core/src/hardware/usb.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/extern/imgui/imgui.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/imgui/imgui_draw.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/imgui/imgui_widgets.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/imgui/imgui_tables.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/imgui/backends/imgui_impl_sdl2.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/imgui/backends/imgui_impl_opengl3.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/implot/implot.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/implot/implot_items.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/imgui/imgui_demo.cpp
)

# Create the Executable
add_executable(Scoped ${SOURCES})

# Define Include Directories
target_include_directories(Scoped PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/core/src
    ${CMAKE_CURRENT_SOURCE_DIR}/core/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/imgui
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/imgui/backends
    ${CMAKE_CURRENT_SOURCE_DIR}/extern/implot
    ${SDL2_INCLUDE_DIRS}
    ${LIBUSB_INCLUDE_DIRS}
)

# Link Libraries
target_link_libraries(Scoped PRIVATE
    SDL2::SDL2
    OpenGL::GL
    ${CMAKE_DL_LIBS}
    ${LIBUSB_LIBRARIES}
)
