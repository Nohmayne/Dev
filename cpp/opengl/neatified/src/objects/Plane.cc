#include "Plane.hh"
#include <iostream>

Plane::Plane(const std::string& shd, const std::string& tex,
        glm::vec3 pos, glm::vec4 rot, glm::vec3 scl)
{
    m_position = pos;
    m_rotation = rot;
    m_scale = scl;

    m_vertices = {
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
         0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
         0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
        -0.5f,  0.5f, 0.0f, 0.0f, 1.0f
    };

    m_indices = {
        0, 1, 2,
        2, 3, 0
    };

    m_vao.bind();

    m_vbo = VertexBuffer(&m_vertices.front(), m_vertices.size() * sizeof(float));
    m_vbo.bind();

    m_ebo = ElementBuffer(&m_indices.front(), m_indices.size());
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

    m_shd = Shader(shd);
    m_shd.bind();

    if (tex != "")
    {
        m_tex = Texture(tex);
        m_tex.bind();
    }
}

Plane::Plane(const std::string& shd, const glm::vec3& clr,
        glm::vec3 pos, glm::vec4 rot, glm::vec3 scl)
{
    m_position = pos;
    m_rotation = rot;
    m_scale = scl;

    m_vertices = {
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
         0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
         0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
        -0.5f,  0.5f, 0.0f, 0.0f, 1.0f
    };

    m_indices = {
        0, 1, 2,
        2, 3, 0
    };

    m_vao.bind();

    m_vbo = VertexBuffer(m_vertices.data(), m_vertices.size() * sizeof(float));
    m_vbo.bind();

    m_ebo = ElementBuffer(m_indices.data(), m_indices.size());
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

    m_shd = Shader(shd);
    m_shd.bind();
    // m_shd.setUniform4f("uColor", clr.x, clr.y, clr.z, 1.f);
}

void Plane::setShaderMVP(glm::mat4& mvp)
{
    // m_shd.setUniformMat4f("uMVP", mvp);
    return;
}

