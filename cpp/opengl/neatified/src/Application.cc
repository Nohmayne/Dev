#include <iostream>

#include "Manager.hh"
#include "objects/Plane.hh"

int main(void)
{
    WindowManager wm(1280, 720, "OpenGL");

    Renderer rnd;
    rnd.setClearColor(0.2f, 0.2f, 0.3f);

    Manager m(rnd, wm);

    Camera* cam = new Camera(glm::vec3(0.f, 0.f, 3.f));

    rnd.setSceneCamera(cam);
    rnd.setAspectRatio(1.f * wm.getWidth() / wm.getHeight());

    Plane* pl = new Plane("src/objects/Object_texture.glsl", "res/images/beans.png");
    pl->rotate(glm::vec4(-55.f, 1.f, 0.f, 0.f));

    while (!wm.shouldClose())
    {
	wm.processInput(*cam);

	rnd.clear();
        rnd.draw(pl);

	wm.swapBuffers();
	wm.pollEvents();
    }
}
