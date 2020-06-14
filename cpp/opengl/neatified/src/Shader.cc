#include "Shader.hh"

Shader::Shader(const std::string& filepath) :
    m_filepath(filepath),
    m_rendererID(0)
{
    m_rendererID = createShader(filepath);
}

Shader::~Shader()
{
    glDeleteProgram(m_rendererID);
}

unsigned int Shader::createShader(const std::string& filepath)
{
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

    unsigned int id = glCreateProgram();
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

    return id;
}

void Shader::bind() const
{
    glUseProgram(m_rendererID);
}

void Shader::unbind() const
{
    glUseProgram(0);
}

void Shader::setUniform4f(const std::string& name, float v0, float v1, float v2, float v3)
{
    glUniform4f(getUniformLocation(name), v0, v1, v2 ,v3);
}

void Shader::setUniformMat4f(const std::string& name, const glm::mat4& matrix)
{
    glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, &matrix[0][0]);
}

void Shader::setUniform1f(const std::string& name, float value)
{
    glUniform1f(getUniformLocation(name), value);
}

void Shader::setUniform1i(const std::string& name, int value)
{
    glUniform1i(getUniformLocation(name), value);
}

unsigned int Shader::getUniformLocation(const std::string& name)
{
    if (m_uniformLocationCache.find(name) != m_uniformLocationCache.end())
	return m_uniformLocationCache[name];
    else
    {
	int loc = glGetUniformLocation(m_rendererID, name.c_str());

    	if (loc == -1)
    	    std::cout << "Warning: Could not locate uniform " << name << std::endl;
	
	m_uniformLocationCache[name] = loc;

    	return loc;
    }
}
