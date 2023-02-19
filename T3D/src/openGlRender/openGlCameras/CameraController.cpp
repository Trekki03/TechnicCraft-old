#include "CameraController.hpp"

namespace T3D::OpenGlRender
{

    //When camera controller is deleted, all registered cameras are also removed
    CameraController::~CameraController()
    {
        for(auto & m_camera : m_cameras)
        {
            delete m_camera;
        }
    }

    // Create / Remove Cameras
    // ------------------------------------------------------------------------------//
    unsigned long long int CameraController::CreateCamera(glm::vec3 initialPosition, float initialPitch, float initialYaw, float initialFov)
    {
        auto* newCamera = new Camera(initialPosition, initialPitch, initialYaw, initialFov);
        m_cameras.push_back(newCamera);
        return newCamera->GetId();
    }

    void CameraController::DeregisterCamera(unsigned long long int cameraID)
    {
        for(unsigned int i = 0; i < m_cameras.size(); i++)
        {
            if(m_cameras.at(i)->GetId() == cameraID)
            {
                m_cameras.erase(m_cameras.begin() + i);
            }
        }
    }

    // Set / Get active camera
    // ------------------------------------------------------------------------------//

    // Set active camera by ID
    void CameraController::SetActiveCamera(unsigned long long int cameraID)
    {
        for(unsigned int i = 0; i < m_cameras.size(); i++)
        {
            if(m_cameras.at(i)->GetId() == cameraID)
            {
                m_activeCameraIndex = i;
            }
        }
    }

    // Set active camera by index
    void CameraController::SetActiveCameraIndex(unsigned int index)
    {
        // If set index is higher than the number of registered cameras. Than the index is set to the last camera.
        if (index > m_cameras.size())
        {
            m_activeCameraIndex = m_cameras.size();
            return;
        }
        m_activeCameraIndex = index;
    }

    Camera* CameraController::GetActiveCameraPointer()
    {
        return m_cameras.at(m_activeCameraIndex);
    }

    unsigned int CameraController::GetActiveCameraIndex() const
    {
        return m_activeCameraIndex;
    }
}
