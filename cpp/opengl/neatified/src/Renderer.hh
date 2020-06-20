#ifndef RENDERER_H
#define RENDERER_H

#include <GL/glew.h>
#include <iostream>

#include "objects/Object.hh"
#include "objects/Plane.hh"
#include "objects/Camera.hh"

class Renderer
{
public:
    Renderer();

    void setClearColor(float red, float green, float blue, float alpha = 1.0f);
    void clear() const;

    void draw(const VertexArray& vao, const ElementBuffer& ebo, const Shader& shader) const;
    void draw(Object* obj);

    void setSceneCamera(Camera* cam);
    void setAspectRatio(const float aspectRatio);
private:
    Camera* m_sceneCamera;
    float m_aspectRatio;
};

#endif
