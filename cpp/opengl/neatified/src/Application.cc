#include <iostream>

#include "Manager.hh"

int main(void)
{
    WindowManager wm(1280, 720, "OpenGL");
    wm.init();

    Renderer rnd;
    rnd.init();
    rnd.setClearColor(0.2f, 0.2f, 0.3f);

    Manager m(rnd, wm);
    m.init();

    while (!wm.shouldClose())
    {
	wm.processInput();

	rnd.clear();

	wm.swapBuffers();
	wm.pollEvents();
    }
}
