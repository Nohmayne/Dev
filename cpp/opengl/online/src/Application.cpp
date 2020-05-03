#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
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

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window))
    {
	// Render
	glClear(GL_COLOR_BUFFER_BIT);

	// Swap buffers
	glfwSwapBuffers(window);

	// Poll/process events
	glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
