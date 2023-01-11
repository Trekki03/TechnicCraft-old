
#include "openGlObjects/VertexBuffer.hpp"

namespace T3D
{
    VertexBuffer::VertexBuffer(const void* dataArray, uint32_t size, GLenum usage)
    {
        glGenBuffers(1, &_objectID);
        VertexBuffer::Bind();
        glBufferData(GL_ARRAY_BUFFER, size, dataArray, usage);
        VertexBuffer::Unbind();
    }

    VertexBuffer::~VertexBuffer()
    {
        VertexBuffer::Unbind();
        glDeleteBuffers(1, &_objectID);
    }
} // T3D