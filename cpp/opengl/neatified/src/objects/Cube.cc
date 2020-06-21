#include "Cube.hh"
#include <iostream>

Cube::Cube(const std::string& shd, const std::string& tex,
        glm::vec3 pos, glm::vec4 rot, glm::vec3 scl)
{
    m_model = *new glm::mat4(1.f);

    m_position = pos;
    m_rotation = rot;
    m_scale = scl;

    m_vertices = {
         0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f, 1.0f, 1.0f,
         0.5f,  0.5f, -0.5f, 0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f, 0.0f, 0.0f,
         0.5f, -0.5f,  0.5f, 1.0f, 0.0f,
         0.5f,  0.5f,  0.5f, 1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f, 0.0f, 1.0f
    };

    m_indices = {
        0, 1, 2,
        2, 3, 0,
        4, 5, 6,
        6, 7, 4,
        1, 4, 7,
        7, 2, 1,
        5, 0, 3,
        3, 6, 5,
        7, 6, 3,
        3, 2, 7,
        1, 0, 5,
        5, 4, 1
    };

    m_vao = *new VertexArray();
    m_vao.bind();

    m_vbo = *new VertexBuffer(&m_vertices.front(), m_vertices.size() * sizeof(float));
    m_vbo.bind();

    m_ebo = *new ElementBuffer(&m_indices.front(), m_indices.size());
    m_ebo.bind();

    VertexAttribute position(0, 3, GL_FLOAT, GL_FALSE);
    VertexAttribute texCoords(1, 2, GL_FLOAT, GL_FALSE);
    m_vao.pushAttribute(position);
    m_vao.pushAttribute(texCoords);

    m_vao.setPointers();

    m_model = glm::translate(m_model, m_position);
    m_model = glm::rotate(m_model, glm::radians(m_rotation.x),
            glm::vec3(m_rotation.y, m_rotation.z, m_rotation.w));
    m_model = glm::scale(m_model, m_scale);

    m_shd = *new Shader(shd);
    m_shd.bind();

    m_tex = *new Texture(tex);
    m_tex.bind();
}

Cube::Cube(const std::string& shd, const glm::vec3& clr,
        glm::vec3 pos, glm::vec4 rot, glm::vec3 scl)
{
    m_model = *new glm::mat4(1.f);

    m_position = pos;
    m_rotation = rot;
    m_scale = scl;

    m_vertices = {
         0.5f, -0.5f, -0.5f, 0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f, 1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f, 1.0f, 1.0f,
         0.5f,  0.5f, -0.5f, 0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f, 0.0f, 0.0f,
         0.5f, -0.5f,  0.5f, 1.0f, 0.0f,
         0.5f,  0.5f,  0.5f, 1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f, 0.0f, 1.0f
    };

    m_indices = {
        0, 1, 2,
        2, 3, 0,
        4, 5, 6,
        6, 7, 4,
        1, 4, 7,
        7, 2, 1,
        5, 0, 3,
        3, 6, 5,
        7, 6, 3,
        3, 2, 7,
        1, 0, 5,
        5, 4, 1
    };

    m_vao = *new VertexArray();
    m_vao.bind();

    m_vbo = *new VertexBuffer(&m_vertices.front(), m_vertices.size() * sizeof(float));
    m_vbo.bind();

    m_ebo = *new ElementBuffer(&m_indices.front(), m_indices.size());
    m_ebo.bind();

    VertexAttribute position(0, 3, GL_FLOAT, GL_FALSE);
    VertexAttribute texCoords(1, 2, GL_FLOAT, GL_FALSE);
    m_vao.pushAttribute(position);
    m_vao.pushAttribute(texCoords);

    m_vao.setPointers();

    m_model = glm::translate(m_model, m_position);
    m_model = glm::rotate(m_model, glm::radians(m_rotation.x),
            glm::vec3(m_rotation.y, m_rotation.z, m_rotation.w));
    m_model = glm::scale(m_model, m_scale);

    m_shd = *new Shader(shd);
    m_shd.bind();
    m_shd.setUniform4f("uColor", clr.x, clr.y, clr.z, 1.f);
}

Cube::~Cube()
{
    delete &m_model;

    delete &m_vao;
    delete &m_vbo;
    delete &m_ebo;

    delete &m_shd;
    delete &m_tex;
}
