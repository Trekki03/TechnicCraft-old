
#ifndef TECHNICCRAFT_OPENGLOBJECT_HPP
#define TECHNICCRAFT_OPENGLOBJECT_HPP

#include <cstdint>

namespace T3D
{

    class OpenGlObject
    {
    protected:
        uint32_t _objectID;
    public:
        virtual inline void Bind() const = 0;
        virtual inline void Unbind() const = 0;
        inline uint32_t GetObjectId() const {return _objectID;}
    };

} // T3D

#endif //TECHNICCRAFT_OPENGLOBJECT_HPP
