#include <iostream>

#include "Manager.hh"
#include "VertexArray.hh"
#include "VertexBuffer.hh"
#include "ElementBuffer.hh"
#include "Shader.hh"
#include "Texture.hh"

#include "vendor/glm/glm.hpp"
#include "vendor/glm/gtc/matrix_transform.hpp"

int main(void)
{
    WindowManager wm(1280, 720, "OpenGL");

    Renderer rnd;
    rnd.setClearColor(0.2f, 0.2f, 0.3f);

    Manager m(rnd, wm);

    float vertices[] = {
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
         0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
         0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
        -0.5f,  0.5f, 0.0f, 0.0f, 1.0f
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

    glm::mat4 proj = glm::ortho(-4.f, 4.f, -2.25f, 2.25f, -1.f, 1.f);

    VertexAttribute position(0, 3, GL_FLOAT, GL_FALSE);
    VertexAttribute texCoords(1, 2, GL_FLOAT, GL_FALSE);
    vao.pushAttribute(position);
    vao.pushAttribute(texCoords);

    vao.setPointers();

    Shader shd("res/shaders/maths.glsl");
    shd.bind();
    shd.setUniformMat4f("uMVP", proj);

    Texture tex("res/images/beans.png");
    tex.bind();

    while (!wm.shouldClose())
    {
	wm.processInput();

	rnd.clear();
	rnd.draw(vao, ebo, shd);

	wm.swapBuffers();
	wm.pollEvents();
    }
}
