#ifndef TECHNICCRAFT_OPENGLOBJECT_HPP
#define TECHNICCRAFT_OPENGLOBJECT_HPP

#include <cstdint>

namespace T3D::OpenGl
{
    /**
     *  Base class for most OpenGL objects.
     *  Featuring an uint32_t to store the ID of the OpenGL object,
     *  a functions to retrieve this ID
     *  as well as pure virtual functions for binding and unbinding the object.
     */
    class OpenGlObject
    {
    protected:
        uint32_t _objectID{}; ///< Member Var for saving the id of the created object.

    public:
        /**
         * Binds the OpenGlObject
         */
        virtual inline void Bind() const = 0;

        /**
         * Unbinds the OpenGlObject
         */
        virtual inline void Unbind() const = 0;

        /**
         * Function to get OpenGL intern object ID.
         * @return The id of the OpenGL object.
         */
        [[nodiscard]] inline uint32_t GetObjectId() const
        {
            return _objectID;
        }
    };

} // T3D

#endif //TECHNICCRAFT_OPENGLOBJECT_HPP
