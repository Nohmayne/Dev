#include "Shader.hh"

Shader::Shader(const char* filepath) 
{
    // ---=== PARSING ===---
    enum Type
    {
	NONE = -1, VERTEX = 0, FRAGMENT = 1
    };

    Type t = Type::NONE;

    std::string svertexSource;
    std::string sfragmentSource;

    std::string currentLine;

    std::ifstream shaderfile(filepath);
    if (shaderfile.is_open())
    {
	while (getline(shaderfile, currentLine))
	{
	    if (currentLine.find("#shader") != std::string::npos)
	    {
		if (currentLine.find("vertex") != std::string::npos)
		    t = Type::VERTEX;
		else if (currentLine.find("fragment") != std::string::npos)
		    t = Type::FRAGMENT;
	    }
	    else
	    {
		if (t == Type::VERTEX)
		    svertexSource += currentLine + '\n';
		else if (t == Type::FRAGMENT)
		    sfragmentSource += currentLine + '\n';
	    }
	}
    }

    // ---=== COMPILATION ===---

    const char* vertexSource = svertexSource.c_str();
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glCompileShader(vertexShader);

    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
	glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
	std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    const char* fragmentSource = sfragmentSource.c_str();
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
	glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
	std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    id = glCreateProgram();
    glAttachShader(id, vertexShader);
    glAttachShader(id, fragmentShader);
    glLinkProgram(id);

    glGetProgramiv(id, GL_LINK_STATUS, &success);
    if (!success)
    {
	glGetProgramInfoLog(id, 512, NULL, infoLog);
	std::cout << "ERROR::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Shader::use()
{
    glUseProgram(id);
}

void Shader::setBool(const std::string &name, bool value) const
{
    glUniform1i(glGetUniformLocation(id, name.c_str()), (int)value);
}

void Shader::setInt(const std::string &name, int value) const
{
    glUniform1i(glGetUniformLocation(id, name.c_str()), value);
}

void Shader::setFloat(const std::string &name, float value) const
{
    glUniform1f(glGetUniformLocation(id, name.c_str()), value);
}
