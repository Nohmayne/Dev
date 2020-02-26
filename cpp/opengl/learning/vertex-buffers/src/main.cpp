#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <stdio.h>
#include <iostream>

/* Shader compilation */
static unsigned int CompileShader(unsigned int type, const std::string& source)
{
    // Create an empty shader
    unsigned int id = glCreateShader(type);

    // Get the source code as a const char*
    const char* src = source.c_str();

    // Assign the source to the shader
    glShaderSource(id, 1, &src, nullptr);

    // Compile the shader
    glCompileShader(id);

    // Test to see if the result of the compilation is good
    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE)
    {
        // if it isn't, print a message
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* message = (char*)alloca(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);
        std::cout << "Failed to compile shader" << std::endl;
        std::cout << message << std::endl;

        // delete the bad shader
        glDeleteShader(id);
        return 0;
    }

    // Return the shader's ID
    return id;
}

/* Create program (vert and frag) off of source code */
static unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader)
{
    // Instantiate variables
    unsigned int program = glCreateProgram();
    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    // Attach both shaders to the shader program
    glAttachShader(program, vs);
    glAttachShader(program, fs);

    // Link them together
    glLinkProgram(program);

    // Validate it, i.e. make sure the shaders can execute
    glValidateProgram(program);

    // Delete the now unused shaders (we have a program now so they're unnecessary)
    glDeleteShader(vs);
    glDeleteShader(fs);

    // Return the program's ID
    return program;
}

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(800, 600, "Vertex Buffers", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Initialize glew */
    if (glewInit() != GLEW_OK)
    {
        /* Problem: glewInit failed, something is seriously wrong. */
        fprintf(stderr, "Error: GLEW init failed");
    }

    std::cout << glGetString(GL_VERSION) << std::endl;

    /* Triangle array */
    float positions[6] = {
        -0.5f, -0.5f,
         0.0f,  0.5f,
         0.5f, -0.5f
    };

    /* Define vertex buffer */
    unsigned int buffer;
    glGenBuffers(1, &buffer);

    /* Bind the buffer */
    glBindBuffer(GL_ARRAY_BUFFER, buffer);

    /* Specify the buffer data */
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

    /* Tell OpenGL what the layout is */
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

    /* Enable the vertex attribute */
    glEnableVertexAttribArray(0);

    std::string vertexShader = 
        "#version 330 core\n"
        "\n"
        "layout(location = 0) in vec4 position;\n"
        "\n"
        "void main()\n"
        "{\n"
        "    gl_Position = position;\n"
        "}\n";
    std::string fragmentShader = 
        "#version 330 core\n"
        "\n"
        "layout(location = 0) out vec4 color;\n"
        "\n"
        "void main()\n"
        "{\n"
        "    color = vec4(1.0, 0.0, 0.0, 1.0);\n" 
        "}\n";

    unsigned int shader = CreateShader(vertexShader, fragmentShader);
    glUseProgram(shader);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Issue a draw call for the buffer */
        glDrawArrays(GL_TRIANGLES, 0, 3);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glDeleteProgram(shader);

    glfwTerminate();
    return 0;
}
