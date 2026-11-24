
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "mouse.h"

int main()
{
    // Initialize GLFW
    if (!glfwInit())
    {
        std::cout << "GLFW Error" << std::endl;
        return -1;
    }

    // OpenGL Version 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    glfwWindowHint(GLFW_OPENGL_PROFILE,
                   GLFW_OPENGL_CORE_PROFILE);

    // Create Window
    GLFWwindow* window = glfwCreateWindow(
        800, 600,
        "OpenGL Mouse Events",
        nullptr, nullptr
    );

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // Initialize GLAD
    if (!gladLoadGLLoader(
        (GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "GLAD Error" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Initialize Mouse Events
     initMouse(window);

    // Background Color
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    // Main Loop
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Cleanup
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

