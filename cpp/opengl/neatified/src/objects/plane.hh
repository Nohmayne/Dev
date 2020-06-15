#ifndef PLANE_H
#define PLANE_H

#include "object.hh"

class Plane : public Object
{
    public:
        Plane(glm::vec3 pos = glm::vec3(0.f),
              glm::vec4 rot = glm::vec4(0.f),
              glm::vec3 scl = glm::vec3(0.f));
    private:
        std::array<float, 20> m_vertices;
        std::array<unsigned int, 6> m_indices;
};

#endif
