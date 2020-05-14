#ifndef RENDERER_H
#define RENDERER_H

#include <GL/glew.h>
#include <iostream>

class Renderer
{
public:
    Renderer();
    void init();
    void setClearColor(float red, float green, float blue, float alpha = 1.0f);
    void clear() const;
};

#endif
