#ifndef TECHNICCRAFT_OPENGLBUFFER_HPP
#define TECHNICCRAFT_OPENGLBUFFER_HPP

#include <cstdint>
#include "OpenGlObject.hpp"

namespace T3D::OpenGl
{
    class OpenGlBuffer: public OpenGlObject
    {
    protected:
        /**
         * Used for size of buffer content in bytes
         */
        uint32_t _bufferSize{};

        /**
         * Used for count of buffer content
         */
        uint32_t _bufferDataCount{};

    public:
        /**
         * Implementation should return pointer to the buffer data.
         * @return pointer to buffer data. Has to be casted by user according to the buffer type.
         */
         // Uses void* so that vertex buffer can return float*, index buffer uint32_t* etc.
        [[nodiscard]] virtual void* GetBufferData() = 0;

        /**
         * Return the size of the buffer content.
         * @return buffer content size in byte.
         */
        inline uint32_t GetBufferSize() const
        {
            return _bufferSize;
        }

        /**
         * Return the data count in buffer.
         * @return buffer content count
         */
        inline uint32_t GetBufferDataCount() const
        {
            return _bufferDataCount;
        }
    };
}
#endif //TECHNICCRAFT_OPENGLBUFFER_HPP
