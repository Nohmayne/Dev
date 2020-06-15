#include "plane.hh"

Plane::Plane(glm::vec3 pos, glm::vec4 rot, glm::vec3 scl)
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
}
