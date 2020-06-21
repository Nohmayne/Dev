#include "Manager.hh"
#include "objects/Cube.hh"

int main(void)
{
    WindowManager wm(1280, 720, "OpenGL");

    Renderer rnd;
    rnd.setClearColor(0.2f, 0.2f, 0.3f);

    Manager m(rnd, wm);

    Camera* cam = new Camera(glm::vec3(0.f, 0.f, 3.f));

    m.setSceneCamera(cam);
    m.setAspectRatio(1.f * wm.getWidth() / wm.getHeight());

    Cube* cb = new Cube("src/objects/Object_texture.glsl", "res/images/beans.png");

    while (!wm.shouldClose())
    {
	wm.processInput();

	rnd.clear();
        rnd.draw(cb);

	wm.swapBuffers();
	wm.pollEvents();
    }
}
