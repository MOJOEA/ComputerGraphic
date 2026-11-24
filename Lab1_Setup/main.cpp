
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Vertex Shader
const char* vertexShaderSource =
"#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"    gl_Position = vec4(aPos, 1.0);\n"
"}\n";

// Fragment Shader
const char* fragmentShaderSource =
"#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"    FragColor = vec4(1.0, 0.0, 0.0, 1.0);\n"
"}\n";

int main()
{
    // 1. Initialize GLFW
    if (!glfwInit())
    {
        std::cout << "GLFW Error" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    glfwWindowHint(GLFW_OPENGL_PROFILE,
                   GLFW_OPENGL_CORE_PROFILE);

    // 2. Create Window
    GLFWwindow* window = glfwCreateWindow(
        800, 600,
        "OpenGL with C++",
        nullptr, nullptr
    );

    if (window == nullptr)
    {
        std::cout << "Window Creation Failed"
                  << std::endl;

        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // 3. Initialize GLAD
    if (!gladLoadGLLoader(
        (GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "GLAD Error" << std::endl;

        glfwTerminate();
        return -1;
    }

    // 4. Triangle Vertices
    float vertices[] =
    {
         0.0f,  0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f
    };

    unsigned int VBO, VAO;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(
        GL_ARRAY_BUFFER,
        sizeof(vertices),
        vertices,
        GL_STATIC_DRAW
    );

    glVertexAttribPointer(
        0, 3, GL_FLOAT, GL_FALSE,
        3 * sizeof(float),
        (void*)0
    );

    glEnableVertexAttribArray(0);

    // 5. Compile Vertex Shader
    unsigned int vertexShader =
        glCreateShader(GL_VERTEX_SHADER);

    glShaderSource(
        vertexShader, 1,
        &vertexShaderSource, nullptr
    );

    glCompileShader(vertexShader);

    // 6. Compile Fragment Shader
    unsigned int fragmentShader =
        glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(
        fragmentShader, 1,
        &fragmentShaderSource, nullptr
    );

    glCompileShader(fragmentShader);

    // 7. Create Shader Program
    unsigned int shaderProgram =
        glCreateProgram();

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);

    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // 8. Render Loop
    while (!glfwWindowShouldClose(window))
    {
        glClearColor(
            0.05f, 0.05f, 0.05f, 1.0f
        );

        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);

        glBindVertexArray(VAO);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // 9. Cleanup
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
