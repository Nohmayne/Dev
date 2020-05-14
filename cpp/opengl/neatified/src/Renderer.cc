#include "Renderer.hh"

Renderer::Renderer() {}

void Renderer::init()
{
    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
	std::cout << "Error initializing renderer." << std::endl;
	std::cout << glewGetErrorString(err) << std::endl;
    }
    std::cout << "Using GLEW " << glewGetString(GLEW_VERSION) << std::endl;
}

void Renderer::setClearColor(float red, float green, float blue, float alpha)
{
    glClearColor(red, green, blue, alpha);
}

void Renderer::clear() const
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
