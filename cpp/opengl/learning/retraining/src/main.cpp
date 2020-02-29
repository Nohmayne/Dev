#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main(void)
{
    GLFWwindow* window;

    if (!glfwInit())
    {
        std::cout << "Error initializing GLFW; Something is seriously wrong" << std::endl;
        return -1;
    }

    window = glfwCreateWindow(800, 600, "Test", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        std::cout << "Error initializing GLFWwindow; Something is seriously wrong" << std::endl;
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
    {
        std::cout << "Error initializing GLEW; Something is seriously wrong" << std::endl;
    }

    float locations[] = 
    {
        -0.5f, -0.5f,
        0.5f, -0.5f,
        0.0f, 0.5f
    };

    unsigned int verts;
    glGenBuffers(1, &verts);
    glBindBuffer(GL_ARRAY_BUFFER, verts);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), &locations, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
