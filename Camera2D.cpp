#include "Camera2D.hpp"

namespace mbgl {
    Camera2D::Camera2D(std::string name, vec3 position, vec3 rotation, vec3 scale)
    : GameObject(name), OrthographicCamera(position, rotation, scale) {}

    void Camera2D::Init() {
        if (data->mainCamera == nullptr)
            data->mainCamera = this;
    }
    void Camera2D::Shutdown() {
        if (data->mainCamera == this)
            data->mainCamera = nullptr;
    }
}