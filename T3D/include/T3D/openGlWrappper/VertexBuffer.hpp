#ifndef TECHNICCRAFT_VERTEXBUFFER_HPP
#define TECHNICCRAFT_VERTEXBUFFER_HPP

#include "OpenGlBuffer.hpp"
#include "glad/glad.h"

namespace T3D::OpenGl
{
    /**
     * A wrapper class for a OpenGL vertex buffer object.
     */
    class VertexBuffer: public OpenGlBuffer
    {
    private:
        /**
         * pointer to store data for output in (GetBufferData())
         */
        float* _data = nullptr;

    public:
        /**
         * Creates a new VBO. And sets its data.
         * The VBO is not bound after initialisation.
         * @param dataArray A pointer to the data that should be copied into the buffer
         * @param size Size of the data in bytes
         * @param usage A usage hint for OpenGL. See usage in https://docs.gl/gl3/glBufferData
         */
        VertexBuffer(const float* dataArray, uint32_t size, GLenum usage);

        /**
         * Unbinds and deletes the buffer on destruction
         */
        ~VertexBuffer();

        /**
         * Returns a pointer to the data stored in the buffer
         * @return pointer to data. Should be casted to float*
         */
        [[nodiscard]] void* GetBufferData() override;

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
