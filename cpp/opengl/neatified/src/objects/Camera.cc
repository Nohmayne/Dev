#include "Camera.hh"

Camera::Camera() :
    m_fov(45.f)
{
    m_position = glm::vec3(0.f, 0.f, 0.f);
    m_target = glm::vec3(0.f, 0.f, 0.f);
    m_direction = glm::vec3(0.f, 0.f, -1.f);

    m_right = glm::normalize(glm::cross(glm::vec3(0.f, 1.f, 0.f), m_direction));
    m_up = glm::cross(m_direction, m_right);

    m_view = glm::lookAt(m_position, m_position + m_direction, m_up);
}

Camera::Camera(glm::vec3 position, glm::vec3 target, float fov) :
    m_fov(fov)
{
    m_position = position;
    m_target = target;

    m_direction = glm::normalize(m_position - m_target);

    m_right = glm::normalize(glm::cross(glm::vec3(0.f, 1.f, 0.f), m_direction));
    m_up = glm::cross(m_direction, m_right);

    m_view = glm::lookAt(m_position, m_position + m_direction, m_up);
}

void Camera::recalculateView(bool recalculateDirection)
{
    if (recalculateDirection)
        m_direction = glm::normalize(m_position - m_target);

    m_right = glm::normalize(glm::cross(glm::vec3(0.f, 1.f, 0.f), m_direction));
    m_up = glm::cross(m_direction, m_right);

    m_view = glm::lookAt(m_position, m_position + m_direction, m_up);
}

void Camera::setPosition(glm::vec3 position)
{
    m_position = position;
    recalculateView(true);
}

void Camera::setTarget(glm::vec3 target)
{
    m_target = target;
    recalculateView(true);
}

void Camera::setDirection(glm::vec3 direction)
{
    m_direction = glm::normalize(direction);
    recalculateView(false);
}
