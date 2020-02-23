#pragma once

#include "Math/Transform.hpp"

namespace mbgl {
    class OrthographicCamera : public Transform {
    public:
        OrthographicCamera(vec3 position = vec3::Zero(), vec3 rotation = vec3::Zero(), vec3 scale = vec3::Zero());
    };
}