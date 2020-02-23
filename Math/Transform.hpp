#pragma once

#include "Vectors.hpp"

namespace mbgl {
    class Transform {
    public:
        vec3 position;
        vec3 rotation;
        vec3 scale;
        Transform(vec3 position = vec3::Zero(), vec3 rotation = vec3::Zero(), vec3 scale = vec3::Zero()) 
        : position(position), rotation(rotation), scale(scale) {}

        static vec2i ToPointOnScreen(vec3 position, Transform* cameraT);
    };
} 

