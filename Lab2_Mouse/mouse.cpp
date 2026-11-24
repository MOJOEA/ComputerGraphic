
#include <iostream>
#include "mouse.h"

// Mouse Button Callback
void mouseButtonCallback(
    GLFWwindow* window,
    int button,
    int action,
    int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT &&
        action == GLFW_PRESS)
    {
        double xpos,ypos;
       // Get Mouse Position
        glfwGetCursorPos(window, &xpos, &ypos);

        std::cout << "Mouse Click Position: "
                  << "X = " << xpos
                  << ", Y = " << ypos
                  << std::endl;
    }

    if (button == GLFW_MOUSE_BUTTON_RIGHT &&
        action == GLFW_PRESS)
    {
        std::cout << "Right Mouse Click" << std::endl;
    }

    if (button == GLFW_MOUSE_BUTTON_MIDDLE &&
        action == GLFW_PRESS)
    {
        std::cout << "Middle Mouse Click" << std::endl;
    }
}



// Initialize Mouse
void initMouse(GLFWwindow* window)
{
    glfwSetMouseButtonCallback(
        window,
        mouseButtonCallback
    );
   
}
