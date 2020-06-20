#ifndef CAMERA_H
#define CAMERA_H

#include "../vendor/glm/glm.hpp"
#include "../vendor/glm/gtc/matrix_transform.hpp"

class Camera
{
    public:
        Camera();
        Camera(glm::vec3 position, glm::vec3 target = glm::vec3(0.f, 0.f, 0.f), float fov = 45.f);

        inline glm::vec3& getPosition() { return m_position; }
        inline glm::vec3& getTarget() { return m_target; }
        inline glm::vec3& getDirection() { return m_direction; }

        inline glm::vec3& getRight() { return m_right; }
        inline glm::vec3& getUp() { return m_up; }

        inline glm::mat4& getViewMatrix() { return m_view; }
        inline float getFOV() { return m_fov; }

        void setPosition(glm::vec3 position);
        void setTarget(glm::vec3 target);
        void setDirection(glm::vec3 direction);
    private:
        glm::vec3 m_position;
        glm::vec3 m_target;
        glm::vec3 m_direction;

        glm::vec3 m_right;
        glm::vec3 m_up;

        glm::mat4 m_view;
        float m_fov;

        void recalculateView(bool recalculateDirection);
};

#endif
