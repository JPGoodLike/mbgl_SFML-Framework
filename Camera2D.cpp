#include "Camera2D.hpp"

namespace mbgl {
    Camera2D::Camera2D(std::string name, vec3 position, vec3 rotation, vec3 scale)
    : GameObject(name), OrthographicCamera(position, rotation, scale) {}
}