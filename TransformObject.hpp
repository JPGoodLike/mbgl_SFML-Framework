#pragma once

#include "GameObject.hpp"
#include "Math/Transformable.hpp"

namespace mbgl {
    class TransformableObject : public GameObject, public Transformable {
    public:
        TransformableObject(std::string name, vec3 position = vec3::Zero(), 
        vec3 rotation = vec3::Zero(), vec3 scale = vec3::One()) 
        : GameObject(name), Transformable(position, rotation, scale) {}
    };
}