#ifndef RENDERER_H
#define RENDERER_H

#include <GL/glew.h>
#include <iostream>

#include "VertexArray.hh"
#include "ElementBuffer.hh"
#include "Shader.hh"

#include "objects/Object.hh"
#include "objects/Plane.hh"

class Renderer
{
public:
    Renderer();

    void setClearColor(float red, float green, float blue, float alpha = 1.0f);
    void clear() const;

    void draw(const VertexArray& vao, const ElementBuffer& ebo, const Shader& shader) const;
    void draw(Object* obj);
};

#endif
