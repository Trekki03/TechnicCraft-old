#ifndef TECHNICCRAFT_VERTEXARRAYOBJECT_HPP
#define TECHNICCRAFT_VERTEXARRAYOBJECT_HPP

#include "OpenGlObject.hpp"
#include "VertexBuffer.hpp"
#include "IndexBuffer.hpp"

namespace T3D::OpenGl
{
    class VertexArrayObject : public OpenGlObject
    {
    private:
        uint32_t _vertexCount{};
        uint32_t _indexCount{};
        VertexBuffer* _vb = nullptr;

    public:

        /**
         * Creates an OpenGL vao
         */
        VertexArrayObject();

        /**
         * Unbinds and deletes VAO
         */
        ~VertexArrayObject();

        /**
         * Links an index buffer to the vao.
         * @param ib index buffer to be linked.
         */
        void SetIndexBuffer(IndexBuffer &ib);

        /**
         * Links a vertex buffer to the vao.
         * @param vb vertex buffer to be linked.
         */
        void SetVertexBuffer(VertexBuffer &vb);

        /**
         * Configures a Vertex Attrib pointer.
         * A VBO has to be set via SetVertexBuffer before usage.
         *
         * @param index Index of the attribPointer
         * @param size number of components per vertex attribute (must be 1, 2, 3 or 4)
         * @param type data type of components (e.g. GL_FLOAT)
         * @param normalized specifies if float/double data should be normalized or used as is
         * @param stride byte offset between to sets of components (start to start)
         * @param offset offset of the components to the start of the buffer (in bytes)
         */
        void ConfigureVertexAttribPointer(uint32_t index, uint32_t size, GLenum type, bool normalized, uint32_t stride, uint32_t offset);

        /**
         * Configures a Vertex Attrib pointer like ConfigureVertexAttribPointer but also enables it afterwards.
         * A VBO has to be set via SetVertexBuffer before usage.
         *
         * @param index Index of the attribPointer
         * @param size number of components per vertex attribute (must be 1, 2, 3 or 4)
         * @param type data type of components (e.g. GL_FLOAT)
         * @param normalized specifies if float/double data should be normalized or used as is
         * @param stride byte offset between to sets of components (start to start)
         * @param offset offset of the components to the start of the buffer (in bytes)
         */
        void ConfigureEnableVertexAttribPointer(uint32_t index, uint32_t size, GLenum type, bool normalized, uint32_t stride, uint32_t offset);

        /**
         * Enables a VertexAttribPointer slot
         * @param index index of the AttribPointer slot
         */
        void EnableVertexAttribPointer(uint32_t index) const;

        /**
         * Disables a VertexAttribPointer slot
         * @param index index of the AttribPointer slot
         */
        void DisableVertexAttribPointer(uint32_t index) const;

        /**
         * Binds the VAO (and with that activates ib, vb and attribPointer)
         */
        inline void Bind() const override { glBindVertexArray(_objectID); }

        /**
         * Unbinds the VAO (and with that deactivates ib, vb and attribPointer)
         */
        inline void Unbind() const override { glBindVertexArray(0); }

        /**
         * Returns the number of Vertices in the linked vertex buffer
         * @return number of vertices
         */
        [[nodiscard]] inline uint32_t GetVertexCount() const { return _vertexCount; }

        /**
         * Returns the number of indices in the linked index buffer.
         * normally the number of elements to be rendered in glDrawElements
         * @return number of indices
         */
        [[nodiscard]] inline uint32_t GetIndexCount() const { return _indexCount; }
    };

} // OpenGl

#endif //TECHNICCRAFT_VERTEXARRAYOBJECT_HPP
