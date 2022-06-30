#include "imgui.h"
#include "examples/imgui_impl_glfw.h"
#include "examples/imgui_impl_opengl3.h"
// OpenGL function loader
#if defined(IMGUI_IMPL_OPENGL_LOADER_GL3W)
    #include <GL/gl3w.h>
#endif
// library for handling windows, inputs and OpenGL graphics
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "GLFW Error: %d: %s\n", error, description);
}

int main()
{
    // GLFW error callback
    glfwSetErrorCallback(glfw_error_callback);
    // initialise GLFW
    if (!glfwInit())
        return EXIT_FAILURE;

    constexpr std::uint32_t window_width = 960;
    constexpr std::uint32_t window_height = 540;
    const std::string window_title = "iSVM";

    // Create window with graphics context
    GLFWwindow* window = glfwCreateWindow(window_width, window_height, window_title.c_str(), NULL, NULL);
    if (window == NULL)
        return EXIT_FAILURE;

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    bool err = gl3wInit() != 0;
    if (err)
        return EXIT_FAILURE;

    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); 
    (void)io;    
    
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 130");

    while (!glfwWindowShouldClose(window))
    {
        // prevent the application window being resized by the user
        glfwSetWindowSize(window, window_width, window_height);
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // ImGui::Begin("Test");
        // ImGui::Button("Button");
        // ImGui::End();

        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwMakeContextCurrent(window);
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClear(GL_COLOR_BUFFER_BIT);
        // white application background
        glClearColor(255, 255, 255, 0);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwMakeContextCurrent(window);
        glfwSwapBuffers(window);
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();
}





