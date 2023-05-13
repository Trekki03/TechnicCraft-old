#include "T3D/openGlWrapper/VertexBuffer.hpp"

namespace t3d::openGl
{
    VertexBuffer::VertexBuffer(const float* dataArray, uint32_t size, GLenum usage)
    {
        _bufferSize = size;
        _bufferDataCount = size/sizeof(float);
        glGenBuffers(1, &_objectID);
        VertexBuffer::Bind();
        glBufferData(GL_ARRAY_BUFFER, size, dataArray, usage);
        VertexBuffer::Unbind();
    }

    VertexBuffer::~VertexBuffer()
    {
        VertexBuffer::Unbind();
        glDeleteBuffers(1, &_objectID);
        delete _data;
    }

    void *VertexBuffer::GetBufferData()
    {
        // Delete last data output and allocate memory.
        delete _data;
        _data = new float[_bufferDataCount];

        Bind();
        glGetBufferSubData(GL_ARRAY_BUFFER, 0, _bufferSize, _data);
        Unbind();
        return static_cast<void*>(_data);
    }
} // T3D