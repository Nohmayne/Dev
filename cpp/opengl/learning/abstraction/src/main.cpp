#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include <csignal>

#include "Renderer.hpp"

#include "VertexBuffer.hpp"
#include "IndexBuffer.hpp"

struct ShaderProgramSource
{
    std::string VertexSource;
    std::string FragmentSource;
};

static ShaderProgramSource parseShader(const std::string& filepath)
{
    std::ifstream stream(filepath);

    enum class ShaderType
    {
	NONE = -1, VERTEX = 0, FRAGMENT = 1
    };

    std::string line;
    std::stringstream ss[2];
    ShaderType type = ShaderType::NONE;

    while (getline(stream, line))
    {
	if (line.find("#shader") != std::string::npos)
	{
	    if (line.find("vertex") != std::string::npos)
		type = ShaderType::VERTEX;
	    else if (line.find("fragment") != std::string::npos)
		type = ShaderType::FRAGMENT;
	}
	else
	    ss[(int)type] << line << '\n';
    }

    return { ss[0].str(), ss[1].str() };
}

static unsigned int compileShader(unsigned int type, const std::string& source)
{
    GLCall(unsigned int id = glCreateShader(type));

    const char* src = source.c_str();
    GLCall(glShaderSource(id, 1, &src, nullptr));

    GLCall(glCompileShader(id));

    int result;
    GLCall(glGetShaderiv(id, GL_COMPILE_STATUS, &result));

    if (result == GL_FALSE)
    {
	int length;
	GLCall(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length));

	char* message = (char*)alloca(length * sizeof(char));
	GLCall(glGetShaderInfoLog(id, length, &length, message));

	std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader!" << std::endl;
	std::cout << message << std::endl;

	GLCall(glDeleteShader(id));
	return 0;
    }

    return id;
}

static unsigned int createProgram(const std::string& vertexShader, const std::string& fragmentShader)
{
    GLCall(unsigned int program = glCreateProgram());

    unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader);

    GLCall(glAttachShader(program, vs));
    GLCall(glAttachShader(program, fs));

    GLCall(glLinkProgram(program));
    GLCall(glValidateProgram(program));

    GLCall(glDeleteShader(vs));
    GLCall(glDeleteShader(fs));

    return program;
}

int main(void)
{
    GLFWwindow* window;

    if (!glfwInit())
    {
	std::cout << "GLFW initialization failed. Exiting..." << std::endl;
	return -1;
    }

    window = glfwCreateWindow(800, 600, "Title", NULL, NULL);
    if (!window)
    {
	std::cout << "GLFW window creation failed. Exiting..." << std::endl;
	glfwTerminate();
	return -1;
    }

    // Set the current OpenGL version to 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    // Set the current OpenGL profile to "core"
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfwMakeContextCurrent(window);

    GLenum err = glewInit();
    if (err != GLEW_OK)
    {
	std::cout << "GLEW initialization failed. Exiting..." << std::endl;
	std::cout << "Error: " << glewGetErrorString(err) << std::endl;
	glfwTerminate();
	return -1;
    }

    GLCall(std::cout << glGetString(GL_VERSION) << std::endl);
    
    // Scope for easier program cleanup
    {
    float positions[] =
    {
	-0.5f, -0.5f,
	0.5f, -0.5f,
	0.5f,  0.5f,
	-0.5f,  0.5f
    };

    unsigned int indices[] =
    {
	0, 1, 2,
	2, 3, 0
    };

    unsigned int vao;
    GLCall(glGenVertexArrays(1, &vao));
    GLCall(glBindVertexArray(vao));

    VertexBuffer vbo(positions, 4 * 2 * sizeof(float));

    GLCall(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), 0));
    GLCall(glEnableVertexAttribArray(0));

    IndexBuffer ibo(indices, 2 * 3);

    ShaderProgramSource source = parseShader("res/basic.glsl");

    unsigned int shader = createProgram(source.VertexSource, source.FragmentSource);

    GLCall(glUseProgram(shader));

    GLCall(int location = glGetUniformLocation(shader, "u_Color"));
    ASSERT(location != -1);

    GLCall(glUniform4f(location, 0.2f, 0.3f, 0.8f, 1.0f));

    GLCall(glBindVertexArray(0));
    GLCall(glUseProgram(0));
    GLCall(glBindBuffer(GL_ARRAY_BUFFER, 0));
    GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));

    while (!glfwWindowShouldClose(window))
    {
	GLCall(glClear(GL_COLOR_BUFFER_BIT));

	GLCall(glUseProgram(shader));
	GLCall(glUniform4f(location, 0.2f, 0.3f, 0.8f, 1.0f));

	GLCall(glBindVertexArray(vao));

	GLCall(glDrawElements(GL_TRIANGLES, 2 * 3, GL_UNSIGNED_INT, nullptr));

	glfwSwapBuffers(window);

	glfwPollEvents();
    }

    GLCall(glDeleteProgram(shader));
    }

    glfwTerminate();
    return 0;
}
