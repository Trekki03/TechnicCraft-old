#include "T3D/openGlWrappper/IndexBuffer.hpp"
#include <iostream>

namespace T3D::OpenGl
{
    IndexBuffer::IndexBuffer(const uint32_t* dataArray, uint32_t size, GLenum usage)
    {
        _bufferSize = size;
        _bufferDataCount = size/sizeof(uint32_t);
        glGenBuffers(1, &_objectID);
        IndexBuffer::Bind();
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, dataArray, usage);
        IndexBuffer::Unbind();
    }

    IndexBuffer::~IndexBuffer()
    {
        IndexBuffer::Unbind();
        glDeleteBuffers(1, &_objectID);
        delete _data;
    }

    void *IndexBuffer::GetBufferData()
    {
        // Delete last data output and allocate memory.
        delete _data;
        _data = new uint32_t[_bufferDataCount];

        Bind();
        glGetBufferSubData(GL_ELEMENT_ARRAY_BUFFER, 0, _bufferSize, _data);
        Unbind();
        return static_cast<void*>(_data);
    }
} // T3D