
#ifndef TECHNICCRAFT_VERTEXBUFFER_HPP
#define TECHNICCRAFT_VERTEXBUFFER_HPP

#include "OpenGlObject.hpp"
#include "glad/glad.h"

namespace T3D::OpenGl
{
    /**
     * A wrapper class for a OpenGL vertex buffer object.
     */
    class VertexBuffer: public OpenGlObject
    {
    public:
        /**
         * Creates a new VBO. And sets its data.
         * The VBO is not bound after initialisation.
         * @param dataArray A pointer to the data that should be copied into the buffer
         * @param size Size of the data in bytes
         * @param usage A usage hint for OpenGL. See usage in https://docs.gl/gl3/glBufferData
         */
        VertexBuffer(const void* dataArray, uint32_t size, GLenum usage);

        /**
         * Unbinds and deletes the buffer on destruction
         */
        ~VertexBuffer();

        /**
         * Activates the buffer
         */
        inline void Bind() const override
        {
            glBindBuffer(GL_ARRAY_BUFFER, _objectID);
        }

        /**
         * deactivates the buffer
         */
        inline void Unbind() const override
        {
            glBindBuffer(GL_ARRAY_BUFFER, 0);
        }
    };

} // T3D

#endif //TECHNICCRAFT_VERTEXBUFFER_HPP
