#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include "Shader.hh"

// Callback function for window resizing
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

// Function for handling user input
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	glfwSetWindowShouldClose(window, true);
}

int main(void)
{
    GLFWwindow* window;

    // Initialize GLFW
    if (!glfwInit())
	return -1;

    // Set OpenGL info
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Window size vars
    const unsigned int windowWidth = 800;
    const unsigned int windowHeight = 600;

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(windowWidth, windowHeight, "learnopengl.com", NULL, NULL);
    if (!window)
    {
	glfwTerminate();
	fprintf(stderr, "Failed to create a window and context. Exiting...\n");
	return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Initialize GLEW
    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
	fprintf(stderr, "Failed to initialize GLEW: %s\n", glewGetErrorString(err));
    }
    fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));

    // Define the viewport size
    glViewport(0, 0, windowWidth, windowHeight);

    // Define the resizing callback function
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Define the vertex matrix
    float vertices[] = {
	-0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,
	 0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,
	 0.5f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f
	// -0.5f,  0.5f, 0.0f
    };

    // Define the two triangles using vertices
    unsigned int indices[] = {
	0, 1, 2,
	// 2, 3, 0
    };

    // Set up a vertex array object to store vertex data
    unsigned int vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    // Construct the vertex buffer objects
    unsigned int vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Construct the element buffer
    unsigned int ebo;
    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // Link vertex attributes
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // Compile and use the shader from file
    Shader shader("res/shaders/individual.glsl");
    shader.use();

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window))
    {
	// Handle input
	processInput(window);

	// Clear the screen
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	// Set the program to draw wireframes
	// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	// Use the proper stuff
	shader.use();
	glBindVertexArray(vao);

	// Draw the shape
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	// Unbind the vao
	glBindVertexArray(0);

	// Swap buffers
	glfwSwapBuffers(window);

	// Poll/process events
	glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
