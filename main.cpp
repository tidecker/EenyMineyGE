#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <iostream>

int main()
{
    if (!glfwInit())
    {
        std::cout << "GLFW failed\n";
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "EenyMeenyGE", nullptr, nullptr);

    if (!window)
    {
        std::cout << "Window creation failed\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "GLAD failed\n";
        return -1;
    }

    glm::vec2 testVector(3.0f, 4.0f);
    std::cout << "GLM test: " << testVector.x << ", " << testVector.y << "\n";

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}