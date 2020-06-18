#include "Renderer.hh"

Renderer::Renderer()
{
    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
	std::cout << "Error initializing renderer." << std::endl;
	std::cout << glewGetErrorString(err) << std::endl;
    }
    std::cout << "Using GLEW " << glewGetString(GLEW_VERSION) << std::endl;

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
}

void Renderer::setClearColor(float red, float green, float blue, float alpha)
{
    glClearColor(red, green, blue, alpha);
}

void Renderer::clear() const
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::draw(const VertexArray& vao, const ElementBuffer& ebo, const Shader& shd) const
{
    shd.bind();
    vao.bind();
    ebo.bind();

    glDrawElements(GL_TRIANGLES, ebo.getCount(), GL_UNSIGNED_INT, 0);
}

void Renderer::draw(Object* obj)
{
    obj->bindAll();

    glDrawElements(GL_TRIANGLES, obj->getEBO().getCount(), GL_UNSIGNED_INT, 0);
}
