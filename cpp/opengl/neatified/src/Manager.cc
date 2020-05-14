#include "Manager.hh"

Manager::Manager(Renderer& rnd, WindowManager& wm) :
    m_renderer(rnd),
    m_windowManager(wm)
{}

void Manager::init()
{
    glfwSetFramebufferSizeCallback(m_windowManager.getWindow(), Manager::framebuffer_size_callback);
}

void Manager::framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}
