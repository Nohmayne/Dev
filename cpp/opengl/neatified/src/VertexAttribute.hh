#ifndef VERTEXATTRIBUTE_H
#define VERTEXATTRIBUTE_H

#include <GL/glew.h>

struct VertexAttribute
{
public:
    unsigned int m_location;
    unsigned int m_count;
    unsigned int m_type;
    unsigned int m_normalized;
};

#endif
