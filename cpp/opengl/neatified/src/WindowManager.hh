#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <GLFW/glfw3.h>
#include <string>
#include <iostream>
#include "objects/Camera.hh"

class WindowManager
{
public:
    WindowManager(int width, int height, std::string title);
    ~WindowManager();

    bool shouldClose() const;
    GLFWwindow* getWindow() const;

    void swapBuffers() const;
    void pollEvents() const;

    int getWidth() const;
    int getHeight() const;

    void processInput();
    void processInput(Camera& cam);

    float deltaTime;
private:
    int m_windowWidth;
    int m_windowHeight;
    std::string m_title;
    GLFWwindow* m_window;

    float m_lastFrame;
    float m_currentFrame;
};

#endif
