
#ifndef MOUSE_H
#define MOUSE_H

#include <GLFW/glfw3.h>

// Register Mouse Events
void initMouse(GLFWwindow* window);

// Mouse Button Event
void mouseButtonCallback(
    GLFWwindow* window,
    int button,
    int action,
    int mods
);

// // Mouse Position Event
// void mousePositionCallback(
//     GLFWwindow* window,
//     double xpos,
//     double ypos
// );

#endif
