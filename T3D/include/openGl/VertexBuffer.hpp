
#ifndef TECHNICCRAFT_VERTEXBUFFER_HPP
#define TECHNICCRAFT_VERTEXBUFFER_HPP

#include "OpenGlObject.hpp"
#include <glad/glad.h>

namespace T3D
{

    class VertexBuffer: public OpenGlObject
    {
    public:
        VertexBuffer(const void* dataArray, uint32_t size, GLenum usage);
        ~VertexBuffer();
        virtual void Bind() const override;
        virtual inline void Unbind() const override;
    };

} // T3D

#endif //TECHNICCRAFT_VERTEXBUFFER_HPP
