
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
        inline void Bind() const override
        {
            glBindBuffer(GL_ARRAY_BUFFER, _objectID);
        }
        inline void Unbind() const override
        {
            glBindBuffer(GL_ARRAY_BUFFER, 0);
        }
    };

} // T3D

#endif //TECHNICCRAFT_VERTEXBUFFER_HPP
