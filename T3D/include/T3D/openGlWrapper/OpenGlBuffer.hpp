#ifndef TECHNICCRAFT_OPENGLBUFFER_HPP
#define TECHNICCRAFT_OPENGLBUFFER_HPP

#include "OpenGlObject.hpp"
#include <cstdint>

namespace t3d::openGl
{
    /**
     *  Base class for OpenGL buffers.
     *  Featuring a uint32_t's to store buffer size and data count.
     *  as well as functions to retrieve this information's.
     *  It also defines a pure virtual functions for getting the content stored in the buffer.
     */
    class OpenGlBuffer: public OpenGlObject
    {
    protected:
        uint32_t _bufferSize{}; ///< Used for size of buffer content in bytes
        uint32_t _bufferDataCount{}; ///< Used for count of buffer content

    public:
        /**
         * returns a pointer to the buffer data.
         * Buffer is unbound after usage
         * @return pointer to buffer data. Has to be casted by user according to the buffer type.
         * @internal Uses void* so that vertex buffer can return float*, index buffer uint32_t* etc.
         */
        [[nodiscard]] virtual void* GetBufferData() = 0;

        /**
         * Return the size of the buffer content.
         * @return buffer content size in byte.
         */
        [[nodiscard]] inline uint32_t GetBufferSize() const
        {
            return _bufferSize;
        }

        /**
         * Return the data count in buffer.
         * @return buffer content count
         */
        [[nodiscard]] inline uint32_t GetBufferDataCount() const
        {
            return _bufferDataCount;
        }
    };
}
#endif //TECHNICCRAFT_OPENGLBUFFER_HPP
