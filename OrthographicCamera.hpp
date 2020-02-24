#pragma once

#include "Math/Transformable.hpp"

namespace mbgl {
    class OrthographicCamera : public Transformable {
    public:
        OrthographicCamera(vec3 position = vec3::Zero(), vec3 rotation = vec3::Zero(), vec3 scale = vec3::One());
    };
}