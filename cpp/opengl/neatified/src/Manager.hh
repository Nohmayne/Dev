#ifndef MANAGER_H
#define MANAGER_H

#include "Renderer.hh"
#include "WindowManager.hh"

class Manager
{
public:
    Manager(Renderer& rnd, WindowManager& wm);

    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
private:
    Renderer& m_renderer;
    WindowManager& m_windowManager;
};

#endif
