#ifndef TECHNICCRAFT_INDEXBUFFER_HPP
#define TECHNICCRAFT_INDEXBUFFER_HPP

#include "OpenGlBuffer.hpp"
#include "glad/glad.h"

namespace t3d::openGl
{
    /**
     * A wrapper class for a OpenGL index buffer object.
     */
    class IndexBuffer: public OpenGlBuffer
    {
    private:
        uint32_t* _data = nullptr; // pointer to store data for output in (GetBufferData())

    public:
        /**
         * Creates a new IBO. And sets its data.
         * The IBO is not bound after initialisation.
         * @param dataArray A pointer to the data that should be copied into the buffer
         * @param size Size of the data in bytes
         * @param usage A usage hint for OpenGL. See usage in https://docs.gl/gl3/glBufferData
         */
        IndexBuffer(const uint32_t* dataArray, uint32_t size, GLenum usage);

        /**
         * Unbinds and deletes the buffer on destruction
         */
        ~IndexBuffer();

        /**
         * @copydoc T3D::OpenGl::OpenGlBuffer::GetBufferData()
         */
        [[nodiscard]] void* GetBufferData() override;

        /**
         * @copydoc T3D::OpenGl::OpenGlObject::Bind()
         */
        inline void Bind() const override
        {
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _objectID);
        }

        /**
         * @copydoc T3D::OpenGl::OpenGlObject::Unbind()
         */
        inline void Unbind() const override
        {
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        }
    };

} // T3D

#endif //TECHNICCRAFT_INDEXBUFFER_HPP
