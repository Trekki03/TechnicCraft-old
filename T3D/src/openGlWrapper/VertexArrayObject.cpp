#include <stdexcept>
#include "T3D/openGlWrapper/VertexArrayObject.hpp"

namespace t3d::openGl
{
    VertexArrayObject::VertexArrayObject()
    {
        glGenVertexArrays(1, &_objectID);
    }

    VertexArrayObject::~VertexArrayObject()
    {
        VertexArrayObject::Unbind();
        glDeleteVertexArrays(1, &_objectID);
    }

    void VertexArrayObject::SetIndexBuffer(IndexBuffer &ib)
    {
        Bind();
        ib.Bind();
        _indexCount = ib.GetBufferDataCount();
        Unbind();
        ib.Unbind();
    }

    void VertexArrayObject::SetVertexBuffer(VertexBuffer &vb)
    {
        _vertexCount = vb.GetBufferDataCount();
        _vb = &vb;
    }

    void VertexArrayObject::ConfigureVertexAttribPointer(uint32_t index, uint32_t size, GLenum type, bool normalized, uint32_t stride, uint32_t offset)
    {
        if(_vb == nullptr)
        {
            throw std::out_of_range("VBO is nullptr. Has to be set via SetVertexBuffer() beforehand!");
        }

        Bind();
        _vb->Bind();
        glVertexAttribPointer(index, (int32_t) size, type, normalized, (int32_t) stride, reinterpret_cast<void*>(offset));
        Unbind();
    }

    void VertexArrayObject::ConfigureEnableVertexAttribPointer(uint32_t index, uint32_t size, GLenum type, bool normalized, uint32_t stride, uint32_t offset)
    {
        if(_vb == nullptr)
        {
            throw std::out_of_range("VBO is nullptr. Has to be set via SetVertexBuffer() beforehand!");
        }

        // Could also be realized by calling ConfigureVertexAttribPointer() and then EnableVertexAttribPointer(). But this would add unnecessary Bind() and Unbind() calls.
        Bind();
        _vb->Bind();
        glVertexAttribPointer(index, (int32_t) size, type, normalized, (int32_t) stride, reinterpret_cast<void*>(offset));
        glEnableVertexAttribArray(index);
        Unbind();
    }

    void VertexArrayObject::EnableVertexAttribPointer(uint32_t index) const
    {
        Bind();
        glEnableVertexAttribArray(index);
        Unbind();
    }

    void VertexArrayObject::DisableVertexAttribPointer(uint32_t index) const
    {
        Bind();
        glDisableVertexAttribArray(index);
        Unbind();
    }

} // OpenGl