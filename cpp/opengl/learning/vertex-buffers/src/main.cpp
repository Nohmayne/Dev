#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

// Struct for returning two vars for shader code
struct ShaderProgramSource
{
    std::string VertexSource;
    std::string FragmentSource;
};

// Parse shaders from file
static ShaderProgramSource ParseShader(const std::string& filepath)
{
    // Access the file at filepath
    std::ifstream stream(filepath);

    // Set up an enum to differentiate shader types
    enum class ShaderType
    {
        NONE = -1, VERTEX = 0, FRAGMENT = 1
    };

    // Go line by line
    std::string line; // Holds the value of the current line
    std::stringstream ss[2]; // Holds the info about both shaders
    ShaderType type = ShaderType::NONE; // Holds the type of the current shader
    while (getline(stream, line))
    {
        // Check if the current line is defining a new shader
        if (line.find("#shader") != std::string::npos)
        {
            // Set the type based on the type of shader defined
            if (line.find("vertex") != std::string::npos)
            {
                // set mode to vertex
                type = ShaderType::VERTEX;
            }
            else if (line.find("fragment") != std::string::npos)
            {
                // set mode to fragment
                type = ShaderType::FRAGMENT;
            }
        }
        else
        {
            // If it's not defining a new shader, push the line to the ss with a \n char
            ss[(int)type] << line << '\n';
        }
    }

    // Return a struct with the two shaders as variables
    return {ss[0].str(), ss[1].str()};
}

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

    ShaderProgramSource source = ParseShader("res/shaders/Basic.shader");
    unsigned int shader = CreateShader(source.VertexSource, source.FragmentSource);
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
