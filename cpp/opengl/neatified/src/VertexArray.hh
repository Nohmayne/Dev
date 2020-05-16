#ifndef VERTEXARRAY_H
#define VERTEXARRAY_H

#include <GL/glew.h>
#include <vector>
#include "VertexAttribute.hh"

class VertexArray
{
public:
    VertexArray();
    ~VertexArray();
private:
    std::vector<VertexAttribute> m_attributes;
    unsigned int m_rendererID;
};

#endif
