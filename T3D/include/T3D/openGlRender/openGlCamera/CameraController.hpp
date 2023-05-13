#ifndef TECHNICCRAFT_CAMERACONTROLLER_HPP
#define TECHNICCRAFT_CAMERACONTROLLER_HPP

#include <vector>
#include "Camera.hpp"

namespace t3d::openGlRender
{
    /**
     * A simple camera controller class. It creates and manages multiple cameras.
     */
    class CameraController
    {
    private:
        unsigned int _activeCameraIndex = 0;
        std::vector<Camera*> _cameras;

    public:
        /**
         * Creates a camera controller
         */
        CameraController() = default;

        /**
         * Deletes a camera controller
         */
        ~CameraController();

        /**
         * Sets the active camera with a cameraID
         * @param cameraID cameraID to be activated
         */
        void SetActiveCamera(uint64_t cameraID);

        /**
         * Sets active camera via index.
         * @param index index to be activated
         */
        void SetActiveCameraIndex(uint32_t index);

        /**
         * Get Pointer to active camera
         * @return pointer to active camera
         */
        [[nodiscard]] Camera* GetActiveCameraPointer();

        /**
         * Get index of active camera
         * @return index of active Camera
         */
        [[nodiscard]] uint32_t GetActiveCameraIndex() const;

        /**
         * Creates a new camera and adds it to the controller. Camera is active after creation.
         * @param initialPosition Initial position vector of the camera
         * @param initialPitch Initial pitch of the camera (caped between -89.0 and 89.0)
         * @param initialYaw Initial yaw of the camera
         * @param initialFov Initial fov of the camera (caped between 1.0 and 45.0)
         * @return return the id of the created camera.
         */
        uint64_t CreateCamera(glm::vec3 initialPosition, float initialPitch, float initialYaw, float initialFov);

        /**
         * removes a camera from controller and deletes it
         * @param cameraID camera (id) to be removed
         */
        void DeregisterCamera(uint64_t cameraID);
    };

}

#endif //TECHNICCRAFT_CAMERACONTROLLER_HPP