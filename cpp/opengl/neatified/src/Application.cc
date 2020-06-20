#include <iostream>

#include "vendor/glm/glm.hpp"
#include "vendor/glm/gtc/matrix_transform.hpp"

#include "Manager.hh"
#include "objects/Plane.hh"

int main(void)
{
    WindowManager wm(1280, 720, "OpenGL");

    Renderer rnd;
    rnd.setClearColor(0.2f, 0.2f, 0.3f);

    Manager m(rnd, wm);

    Plane* pl = new Plane("src/objects/Object_color.glsl", glm::vec3(0.5f, 1.0f, 0.7f));

    glm::mat4 model = glm::rotate(glm::mat4(1.f), glm::radians(-55.f), glm::vec3(1.f, 0.f, 0.f));
    glm::mat4 view = glm::translate(glm::mat4(1.f), glm::vec3(0.f, 0.f, -3.f));
    glm::mat4 proj = glm::perspective(glm::radians(45.f), 1.f * wm.getWidth() / wm.getHeight(), 0.1f, 100.0f);

    glm::mat4 mvp = proj * view * model;

    for (size_t i = 0; i < 4; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            std::cout << pl->getModelMatrix()[i][j] << ", ";
        }
        std::cout << std::endl;
    }

    pl->bindAll();
    pl->setShaderMVP(mvp);
    pl->unbindAll();

    while (!wm.shouldClose())
    {
	wm.processInput();

	rnd.clear();

        rnd.draw(pl);

	wm.swapBuffers();
	wm.pollEvents();
    }
}
