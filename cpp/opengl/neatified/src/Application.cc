#include <iostream>

#include "Manager.hh"
#include "VertexArray.hh"
#include "VertexBuffer.hh"
#include "ElementBuffer.hh"
#include "Shader.hh"
#include "Texture.hh"

#include "vendor/glm/glm.hpp"
#include "vendor/glm/gtc/matrix_transform.hpp"

#include "objects/Plane.hh"

int main(void)
{
    WindowManager wm(1280, 720, "OpenGL");

    Renderer rnd;
    rnd.setClearColor(0.2f, 0.2f, 0.3f);

    Manager m(rnd, wm);

    Plane* pl = new Plane("src/objects/Object_color.glsl", glm::vec3(0.5f, 1.0f, 0.7f));

    glm::mat4 model(1.f);
    model = glm::rotate(model, glm::radians(-55.f), glm::vec3(1.f, 0.f, 0.f));

    glm::mat4 view(1.f);
    view = glm::translate(view, glm::vec3(0.f, 0.f, -3.f));

    glm::mat4 proj = glm::perspective(glm::radians(45.f), 1.f * wm.getWidth() / wm.getHeight(), 0.1f, 100.0f);

    glm::mat4 mvp = proj * view * model;

    pl->bindAll();
    pl->setShaderMVP(mvp);
    pl->unbindAll();

    while (!wm.shouldClose())
    {
	wm.processInput();

	rnd.clear();

        pl->bindAll();
        std::cout << "Drawing frame..." << std::endl;
        rnd.draw(pl);
        std::cout << "Drawn" << std::endl;

	wm.swapBuffers();
	wm.pollEvents();
    }
}
