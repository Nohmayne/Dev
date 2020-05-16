#include "VertexArray.hh"

VertexArray::VertexArray()
{
    glGenVertexArrays(1, &m_rendererID);
}
