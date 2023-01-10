
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
        virtual void Bind() const = 0;
        virtual inline void Unbind() const = 0;
    };

} // T3D

#endif //TECHNICCRAFT_OPENGLOBJECT_HPP
