#ifndef TECHNICCRAFT_CAMERA_HPP
#define TECHNICCRAFT_CAMERA_HPP

#include "../../../../../cmake-build-debug/T3D/dependencies/glm/glm/glm.hpp"

namespace T3D::OpenGlRender
{

    class Camera
    {
    private:
        unsigned long long int m_cameraID;
        float m_pitch;
        float m_yaw;
        float m_fov;
        float m_xPos;
        float m_yPos;
        float m_zPos;

    public:
        Camera() = delete;
        Camera(glm::vec3 position, float pitch, float yaw, float fov);

        void AddPitch(float pitch);
        void AddYaw(float yaw);
        void AddFov(float fov);
        void AddXPos(float xPos);
        void AddYPos(float yPos);
        void AddZPos(float zPos);
        void AddPositionVector(glm::vec3 position);

        void SetPitch(float pitch);
        void SetYaw(float yaw);
        void SetFov(float fov);
        void SetXPos(float xPos);
        void SetYPos(float yPos);
        void SetZPos(float zPos);
        void SetPositionVector(glm::vec3 position);

        [[nodiscard]] float GetPitch() const;
        [[nodiscard]] float GetYaw() const;
        [[nodiscard]] float GetFov() const;
        [[nodiscard]] unsigned long long int GetId() const;
        [[nodiscard]] glm::vec3 GetDirectionVector() const;
        [[nodiscard]] glm::vec3 GetPositionVector() const;
    };

}

#endif //TECHNICCRAFT_CAMERA_HPP
