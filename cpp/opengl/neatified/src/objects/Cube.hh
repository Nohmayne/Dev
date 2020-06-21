#ifndef CUBE_H
#define CUBE_H

#include "Object.hh"

class Cube : public Object
{
    public:
        Cube(const std::string& shd, const std::string& tex = "",
              glm::vec3 pos = glm::vec3(0.f),
              glm::vec4 rot = glm::vec4(0.f, 1.f, 0.f, 0.f),
              glm::vec3 scl = glm::vec3(1.f));

        Cube(const std::string& shd, const glm::vec3& clr,
              glm::vec3 pos = glm::vec3(0.f),
              glm::vec4 rot = glm::vec4(0.f, 1.f, 0.f, 0.f),
              glm::vec3 scl = glm::vec3(1.f));

        ~Cube();
    private:
        std::array<float, 120> m_vertices;
        std::array<unsigned int, 36> m_indices;
};

#endif
