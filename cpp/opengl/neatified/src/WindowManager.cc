#include "WindowManager.hh"

WindowManager::WindowManager(int width, int height, std::string title) :
    deltaTime(0.f),
    m_windowWidth(width),
    m_windowHeight(height),
    m_title(title),
    m_lastFrame(0.f),
    m_currentFrame(0.f)
{
    if (!glfwInit())
    {
	std::cout << "Error initializing GLFW in WM" << std::endl;
	return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_window = glfwCreateWindow(m_windowWidth, m_windowHeight, m_title.c_str(), NULL, NULL);
    if (!m_window)
    {
	std::cout << "Error creating window in WM" << std::endl;
	glfwTerminate();
    }

    glfwMakeContextCurrent(m_window);
}

WindowManager::~WindowManager()
{
    glfwTerminate();
}

bool WindowManager::shouldClose() const
{
    return glfwWindowShouldClose(m_window);
}

GLFWwindow* WindowManager::getWindow() const
{
    return m_window;
}

void WindowManager::swapBuffers() const
{
    glfwSwapBuffers(m_window);
}

void WindowManager::pollEvents() const
{
    glfwPollEvents();
}

int WindowManager::getWidth() const
{
    return m_windowWidth;
}

int WindowManager::getHeight() const
{
    return m_windowHeight;
}

void WindowManager::processInput()
{
    m_currentFrame = glfwGetTime();
    deltaTime = m_currentFrame - m_lastFrame;
    m_lastFrame = m_currentFrame;

    if (glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	glfwSetWindowShouldClose(m_window, true);
}

void WindowManager::processInput(Camera& cam)
{
    m_currentFrame = glfwGetTime();
    deltaTime = m_currentFrame - m_lastFrame;
    m_lastFrame = m_currentFrame;

    float cameraSpeed = 2.5f * deltaTime;

    if (glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	glfwSetWindowShouldClose(m_window, true);
    if (glfwGetKey(m_window, GLFW_KEY_W) == GLFW_PRESS)
        cam.setPosition(cam.getPosition() + cameraSpeed * cam.getDirection());
    if (glfwGetKey(m_window, GLFW_KEY_S) == GLFW_PRESS)
        cam.setPosition(cam.getPosition() - cameraSpeed * cam.getDirection());
    if (glfwGetKey(m_window, GLFW_KEY_A) == GLFW_PRESS)
        cam.setPosition(cam.getPosition() - cameraSpeed * cam.getRight());
    if (glfwGetKey(m_window, GLFW_KEY_D) == GLFW_PRESS)
        cam.setPosition(cam.getPosition() + cameraSpeed * cam.getRight());
}
