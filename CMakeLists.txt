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

add_library(glad STATIC "./libs/glad-master/build/src/glad.c")
target_include_directories(glad PUBLIC "./libs/glad-master/build/include")

add_library(imgui STATIC 
  ../libs/imgui-master/imgui.cpp
  ../libs/imgui-master/imgui_demo.cpp
  ../libs/imgui-master/imgui_draw.cpp
  ../libs/imgui-master/imgui_widgets.cpp
  ../libs/imgui-master/examples/imgui_impl_glfw.cpp
  ../libs/imgui-master/examples/imgui_impl_opengl2.cpp
)

target_include_directories(imgui PRIVATE "./libs/imgui-master/examples" "./libs/imgui-master")

add_executable(main src/example.cpp)

target_include_directories(main PRIVATE
"./libs/imgui-master"
"./libs/imgui-master/examples"
"./libs/glfw-master/include"
"./libs/glad-master/build/include/glad")

target_link_libraries(main PRIVATE glfw glad imgui OpenGL::GL)