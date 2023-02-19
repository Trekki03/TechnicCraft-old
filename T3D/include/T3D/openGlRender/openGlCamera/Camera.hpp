#ifndef TECHNICCRAFT_CAMERA_HPP
#define TECHNICCRAFT_CAMERA_HPP

#include "glm/glm.hpp"

namespace T3D::OpenGlRender
{
    /**
     * A simple Camera class. The Camera safes changeable position and
     * rotation and can creates vectors for calculation accordingly
     */
    class Camera
    {

    private:
        uint32_t m_cameraID;
        float m_pitch;
        float m_yaw;
        float m_fov;
        float m_xPos;
        float m_yPos;
        float m_zPos;

    public:
        /**
         * Creates an Camera object with start position, rotation and fov
         * @param position start position
         * @param pitch start pitch
         * @param yaw start yaw
         * @param fov start fov
         */
        Camera(glm::vec3 position, float pitch, float yaw, float fov);

        /**
         * Increases pitch to the camera (or decreases, if negativ)
         * pitch caped between -89 and 89
         * @param pitch pitch to be added
         */
        void AddPitch(float pitch);

        /**
         * Increases yaw to the camera (or decreases, if negativ)
         * @param yaw yaw to be added
         */
        void AddYaw(float yaw);

        /**
         * Increases fov to the camera (or decreases, if negativ)
         * fov caped between 1 and 45
         * @param fov fov to be added
         */
        void AddFov(float fov);

        /**
         * Increases the xPos of the camera (or decreases, if negativ)
         * @param xPos xPos to be added
         */
        void AddXPos(float xPos);

        /**
         * Increases the yPos of the camera (or decreases, if negativ)
         * @param yPos yPos to be added
         */
        void AddYPos(float yPos);

        /**
         * Increases the zPos of the camera (or decreases, if negativ)
         * @param zPos zPos to be added
         */
        void AddZPos(float zPos);

        /**
         * Increases the position of the camera (or decreases, if negativ) in all directions by given vector
         * @param position position to be added
         */
        void AddPositionVector(glm::vec3 position);

        /**
         * Sets the pitch of the camera to a given value
         * pitch caped between -89 and 89
         * @param pitch pitch to be set
         */
        void SetPitch(float pitch);

        /**
         * Sets the yaw of the camera to a given value
         * @param yaw yaw to be set
         */
        void SetYaw(float yaw);

        /**
         * Sets the fov of the camera to a given value
         * * fov caped between 1 and 45
         * @param fov fov to be set
         */
        void SetFov(float fov);

        /**
         * Sets the xPos of the camera to a given value
         * @param xPos xPos to be set
         */
        void SetXPos(float xPos);

        /**
         * Sets the yPos of the camera to a given value
         * @param yPos yPos to be set
         */
        void SetYPos(float yPos);

        /**
         * Sets the zPos of the camera to a given value
         * @param zPos zPos to be set
         */
        void SetZPos(float zPos);

        /**
         * Sets the position of the camera to a given vector
         * @param position position to be set
         */
        void SetPositionVector(glm::vec3 position);

        /**
         * Returns the current pitch of the camera
         * @return camera pitch
         */
        [[nodiscard]] float GetPitch() const;

        /**
         * Returns the current yaw of the camera
         * @return camera yaw
         */
        [[nodiscard]] float GetYaw() const;

        /**
         * Returns the current fov of the camera
         * @return camera fov
         */
        [[nodiscard]] float GetFov() const;

        /**
         * Returns the id of the camera
         * @return camera id
         */
        [[nodiscard]] uint32_t GetId() const;

        /**
         * Returns the current direction vector of the camera
         * @return camera direction vector
         */
        [[nodiscard]] glm::vec3 GetDirectionVector() const;

        /**
         * Returns the current position vector of the camera
         * @return camera position vector
         */
        [[nodiscard]] glm::vec3 GetPositionVector() const;
    };
}

#endif //TECHNICCRAFT_CAMERA_HPP
