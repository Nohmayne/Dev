#ifndef OBJECT_H
#define OBJECT_H

#include "../VertexArray.hh"
#include "../VertexBuffer.hh"
#include "../ElementBuffer.hh"
#include "../Shader.hh"
#include "../Texture.hh"

#include "../vendor/glm/glm.hpp"
#include "../vendor/glm/gtc/matrix_transform.hpp"
#include "../vendor/glm/gtc/type_ptr.hpp"

class Object
{
    public:
        Object();

        inline glm::vec3& getPosition() { return m_position; }
        inline glm::vec4& getRotation() { return m_rotation; }
        inline glm::vec3& getScale() { return m_scale; }

        inline glm::mat4 getModelMatrix() { return m_model; }

        inline VertexArray& getVAO() { return m_vao; }
        inline VertexBuffer& getVBO() { return m_vbo; }
        inline ElementBuffer& getEBO() { return m_ebo; }
        inline Shader& getSHD() { return m_shd; }

        void bindAll() const;
        void unbindAll() const;

        void translate(const glm::vec3& translation);
        void rotate(const glm::vec4& rotation);
        void scale(const glm::vec3& scaleFactor);

        void setShaderMVP(const glm::mat4& mvp);
    protected:
        VertexArray m_vao;
        VertexBuffer m_vbo;
        ElementBuffer m_ebo;

        Shader m_shd;
        Texture m_tex;

        glm::vec3 m_position;
        glm::vec4 m_rotation;
        glm::vec3 m_scale;

        glm::mat4 m_model;
};

#endif
