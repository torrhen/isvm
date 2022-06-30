cmake_minimum_required(VERSION 3.20)

project(isvm VERSION 1.0 LANGUAGES C CXX)

if(WIN32)
    # Windows platforms (incl. Win64) not supported...yet
    message(FATAL_ERROR "Error: Windows platforms not supported.")
elseif(APPLE)
    # macOS, iOS, tvOS or watchOS platforms not supported
    message(FATAL_ERROR "Error: Apple platforms not supported.")
elseif(ANDROID)
    # android not supported
    message(FATAL_ERROR "Error: Android platform not supported.")
elseif(IOS)
    # IOS not supported
    message(FATAL_ERROR "Error: IOS platform not supported.")
endif()

# search for installed glfw library files
find_package(glfw3 REQUIRED)
# search for installed gl3w library files
find_package(gl3w REQUIRED)

# create static library for ImGui
add_library(imgui STATIC 
  ../external/imgui-master/imgui.cpp
  ../external/imgui-master/imgui_demo.cpp
  ../external/imgui-master/imgui_draw.cpp
  ../external/imgui-master/imgui_widgets.cpp
  ../external/imgui-master/examples/imgui_impl_glfw.cpp
  ../external/imgui-master/examples/imgui_impl_opengl3.cpp
)
# include public headers for static library
target_include_directories(imgui PUBLIC "./external/imgui-master")
target_link_libraries(imgui PUBLIC gl3w glfw)

# create executable target
add_executable(isvm src/application.cpp)
# link libraries to target. visibility of include directories are transistive and visible to executable
target_link_libraries(isvm PRIVATE imgui)
# allow all warnings as errors
target_compile_options(isvm PRIVATE -Wall -Wextra -pedantic -Werror)
# install the executable binary
install(TARGETS isvm DESTINATION ${CMAKE_SOURCE_DIR}/bin)