
#include "T3D/openGlWrappper/VertexBuffer.hpp"

namespace T3D::OpenGl
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