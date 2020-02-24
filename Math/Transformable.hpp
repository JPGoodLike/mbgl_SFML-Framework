#pragma once

#include "Vectors.hpp"

namespace mbgl {
    class Transformable {
    public:
        vec3 position;
        vec3 rotation;
        vec3 scale;
        Transformable(vec3 position = vec3::Zero(), vec3 rotation = vec3::Zero(), vec3 scale = vec3::One()) 
        : position(position), rotation(rotation), scale(scale) {}

        static vec2i ToPointOnScreen(vec3 position, Transformable* cameraT);
    };
} 

