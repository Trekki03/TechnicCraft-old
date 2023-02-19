#ifndef TECHNICCRAFT_CAMERACONTROLLER_HPP
#define TECHNICCRAFT_CAMERACONTROLLER_HPP

#include "../../../../../../../../../../Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX13.1.sdk/usr/include/c++/v1/vector"
#include "Camera.hpp"

namespace T3D::OpenGlRender
{

    class CameraController
    {
    private:
        unsigned int m_activeCameraIndex = 0;
        std::vector<Camera*> m_cameras;

    public:
        CameraController() = default;
        ~CameraController();

        void SetActiveCamera(unsigned long long int cameraID);
        void SetActiveCameraIndex(unsigned int index);
        Camera* GetActiveCameraPointer();
        unsigned int GetActiveCameraIndex() const;

        unsigned long long int CreateCamera(glm::vec3 initialPosition, float initialPitch, float initialYaw, float initialFov);
        void DeregisterCamera(unsigned long long int cameraID);
    };

}

#endif //TECHNICCRAFT_CAMERACONTROLLER_HPP
