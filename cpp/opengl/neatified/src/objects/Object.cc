#include "Object.hh"

Object::Object() :
    m_vbo(0, 0), m_ebo(0, 0), m_shd(""), m_tex("")
{}

void Object::translate(glm::vec3& translation)
{
    m_model = glm::translate(m_model, translation);
}

void Object::rotate(glm::vec4& rotation)
{
    m_model = glm::rotate(m_model, glm::radians(rotation.x),
            glm::vec3(rotation.y, rotation.z, rotation.w));
}

void Object::scale(glm::vec3& scaleFactor)
{
    m_model = glm::scale(m_model, scaleFactor);
}

void Object::bindAll() const
{
    m_vao.bind();
    m_vbo.bind();
    m_ebo.bind();

    m_shd.bind();

    if (m_tex.getHeight() != 0 && m_tex.getWidth() != 0)
        m_tex.bind();
}

void Object::unbindAll() const
{
    m_vao.unbind();
    m_vbo.unbind();
    m_ebo.unbind();

    m_shd.unbind();

    if (m_tex.getHeight() != 0 && m_tex.getWidth() != 0)
        m_tex.unbind();
}
