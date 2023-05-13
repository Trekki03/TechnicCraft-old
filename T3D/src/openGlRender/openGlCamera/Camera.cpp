#include "T3D/openGlRender/openGlCamera/Camera.hpp"

namespace t3d::openGlRender
{
    /*
    * Initialize members and gives CameraID and value corresponding to the address of the pointer.
    * This has the advantage, that the ID of the Camera is unique, because there can't be another object with the
    * same address, as long as this instance exists.
    */
    Camera::Camera(glm::vec3 position, float pitch, float yaw, float fov) :
            _pitch(pitch), _yaw(yaw), _fov(fov), _xPos(position.x), _yPos(position.y), _zPos(position.z)
    {
        _cameraID = reinterpret_cast<uint64_t>(this);
    }


    // Adding Functions
    // ------------------------------------------------------------------------------//

    void Camera::AddFov(float fov)
    {
        float newFov = _fov + fov;

        // FOV has to be between 1.0 and 45.0
        if (newFov < 1.0f)
        {
            newFov = 1.0f;
        }
        else if (newFov > 45.0f)
        {
            newFov = 45.0f;
        }

        _fov = newFov;
    }

    void Camera::AddPitch(float pitch)
    {
        float newPitch = _pitch + pitch;

        // FOV has to be between -89.0 and 89.0
        if (newPitch > 89.0f)
        {
            newPitch = 89.0f;
        }
        else if (newPitch < -89.0f)
        {
            newPitch = -89.0f;
        }

        _pitch = newPitch;
    }

    void Camera::AddYaw(float yaw)
    {
        _yaw += yaw;
    }

    void Camera::AddXPos(float xPos)
    {
        _xPos += xPos;
    }

    void Camera::AddYPos(float yPos)
    {
        _yPos += yPos;
    }

    void Camera::AddZPos(float zPos)
    {
        _zPos += zPos;
    }

    void Camera::AddPositionVector(glm::vec3 position)
    {
        _xPos += position.x;
        _yPos += position.y;
        _zPos += position.z;
    }

    // Setter Functions
    // ------------------------------------------------------------------------------//

    void Camera::SetFov(float fov)
    {
        float newFov = fov;

        // FOV has to be between 1.0 and 45.0
        if (newFov < 1.0f)
        {
            newFov = 1.0f;
        }
        else if (newFov > 45.0f)
        {
            newFov = 45.0f;
        }

        _fov = newFov;
    }

    void Camera::SetPitch(float pitch)
    {
        float newPitch = pitch;

        // FOV has to be between -89.0 and 89.0
        if (newPitch > 89.0f)
        {
            newPitch = 89.0f;
        }
        else if (newPitch < -89.0f)
        {
            newPitch = -89.0f;
        }

        _pitch = newPitch;
    }

    void Camera::SetYaw(float yaw)
    {
        _yaw = yaw;
    }

    void Camera::SetXPos(float xPos)
    {
        _xPos = xPos;
    }

    void Camera::SetYPos(float yPos)
    {
        _yPos = yPos;
    }

    void Camera::SetZPos(float zPos)
    {
        _zPos = zPos;
    }

    void Camera::SetPositionVector(glm::vec3 position)
    {
        _xPos = position.x;
        _yPos = position.y;
        _zPos = position.z;
    }

    // Getter Functions
    // ------------------------------------------------------------------------------//

    uint64_t Camera::GetId() const
    {
        return _cameraID;
    }

    float Camera::GetFov() const
    {
        return _fov;
    }

    float Camera::GetYaw() const
    {
        return _yaw;
    }

    float Camera::GetPitch() const
    {
        return _pitch;
    }

    glm::vec3 Camera::GetDirectionVector() const
    {
        glm::vec3 direction;
        direction.x = cosf(glm::radians(_yaw)) * cosf(glm::radians(_pitch));
        direction.y = sinf(glm::radians(_pitch));
        direction.z = sinf(glm::radians(_yaw)) * cosf(glm::radians(_pitch));
        return glm::normalize(direction);
    }

    glm::vec3 Camera::GetPositionVector() const
    {
        return {_xPos, _yPos, _zPos};
    }
}