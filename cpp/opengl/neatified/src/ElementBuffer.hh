#ifndef ELEMENTBUFFER_H
#define ELEMENTBUFFER_H

#include <GL/glew.h>

class ElementBuffer
{
public:
    ElementBuffer(const void* data, unsigned int size);
    ~ElementBuffer();

    void bind() const;
    void unbind() const;
private:
    unsigned int m_rendererID;
};

#endif
