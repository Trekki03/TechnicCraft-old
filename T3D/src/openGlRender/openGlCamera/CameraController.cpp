#include "T3D/openGlRender/openGlCamera/CameraController.hpp"

namespace t3d::openGlRender
{

    //When camera controller is deleted, all registered cameras are also removed
    CameraController::~CameraController()
    {
        for(auto & m_camera : _cameras)
        {
            delete m_camera;
        }
    }

    // Create / Remove Cameras
    // ------------------------------------------------------------------------------//
    uint64_t CameraController::CreateCamera(glm::vec3 initialPosition, float initialPitch, float initialYaw, float initialFov)
    {
        auto* newCamera = new Camera(initialPosition, initialPitch, initialYaw, initialFov);
        _cameras.push_back(newCamera);
        uint32_t cameraID = newCamera->GetId();
        SetActiveCamera(cameraID);
        return cameraID;
    }

    void CameraController::DeregisterCamera(uint64_t cameraID)
    {
        for(unsigned int i = 0; i < _cameras.size(); i++)
        {
            if(_cameras.at(i)->GetId() == cameraID)
            {
                _cameras.erase(_cameras.begin() + i);
            }
        }
    }

    // Set / Get active camera
    // ------------------------------------------------------------------------------//

    // Set active camera by ID
    void CameraController::SetActiveCamera(uint64_t cameraID)
    {
        for(unsigned int i = 0; i < _cameras.size(); i++)
        {
            if(_cameras.at(i)->GetId() == cameraID)
            {
                _activeCameraIndex = i;
            }
        }
    }

    // Set active camera by index
    void CameraController::SetActiveCameraIndex(unsigned int index)
    {
        // If set index is higher than the number of registered cameras. Then the index is set to the last camera.
        if (index > _cameras.size())
        {
            _activeCameraIndex = _cameras.size();
            return;
        }
        _activeCameraIndex = index;
    }

    Camera* CameraController::GetActiveCameraPointer()
    {
        return _cameras.at(_activeCameraIndex);
    }

    unsigned int CameraController::GetActiveCameraIndex() const
    {
        return _activeCameraIndex;
    }
}
