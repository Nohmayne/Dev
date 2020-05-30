#include <iostream>

#include "Manager.hh"
#include "VertexArray.hh"
#include "VertexBuffer.hh"
#include "ElementBuffer.hh"
#include "Shader.hh"

int main(void)
{
    WindowManager wm(1280, 720, "OpenGL");

    Renderer rnd;
    rnd.setClearColor(0.2f, 0.2f, 0.3f);

    Manager m(rnd, wm);

    float vertices[] = {
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.5f,  0.5f, 0.0f,
	-0.5f,  0.5f, 0.0f
    };

    unsigned int indices[] = {
	0, 1, 2,
	2, 3, 0
    };

    VertexArray vao;
    vao.bind();

    VertexBuffer vbo(vertices, sizeof(vertices));
    vbo.bind();

    ElementBuffer ebo(indices, sizeof(indices));
    ebo.bind();

    VertexAttribute position(0, 3, GL_FLOAT, GL_FALSE);
    vao.pushAttribute(position);

    vao.setPointers();

    Shader shd("res/shaders/basic.glsl");
    shd.bind();

    while (!wm.shouldClose())
    {
	wm.processInput();

	rnd.clear();
	rnd.draw(vao, ebo, shd);

	wm.swapBuffers();
	wm.pollEvents();
    }
}
