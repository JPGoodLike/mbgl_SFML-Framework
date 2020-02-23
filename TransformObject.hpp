#pragma once

#include "GameObject.hpp"
#include "Math/Transform.hpp"

namespace mbgl {
    class TransformObject : public GameObject, public Transform {
    public:
        TransformObject(std::string name, vec3 position = vec3::Zero(), 
        vec3 rotation = vec3::Zero(), vec3 scale = vec3::Zero()) 
        : GameObject(name), Transform(position, rotation, scale) {}
    };
}