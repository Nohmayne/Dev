#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <GLFW/glfw3.h>
#include <string>
#include <iostream>

class WindowManager
{
public:
    WindowManager(int width, int height, std::string title);
    ~WindowManager();

    void init();
    bool shouldClose() const;
    GLFWwindow* getWindow() const;

    void swapBuffers() const;
    void pollEvents() const;

    int getWidth() const;
    int getHeight() const;

    void processInput();
private:
    int m_windowWidth;
    int m_windowHeight;
    std::string m_title;
    GLFWwindow* m_window;
};

#endif
