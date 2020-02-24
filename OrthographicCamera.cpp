#include "OrthographicCamera.hpp"

namespace mbgl {
    OrthographicCamera::OrthographicCamera(vec3 position, vec3 rotation, vec3 scale)
    : Transformable(position, rotation, scale) {}
}