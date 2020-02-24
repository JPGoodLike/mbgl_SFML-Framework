#pragma once

#include "GameObject.hpp"
#include "Math/Transformable.hpp"
#include "Renderable2D.hpp"

namespace mbgl {
    class RenderObject2D : public GameObject, public Renderable2D {
    public:
        RenderObject2D(std::string name, vec3 position = vec3::Zero(), 
        vec3 rotation = vec3::Zero(), vec3 scale = vec3::One()) 
        : GameObject(name), Renderable2D(position, rotation, scale) {}

        void Init() override {
            data->sceneManager.GetCurrentScene()->AddRenderable2D(this);
        }
        void Shutdown() override {
            data->sceneManager.GetCurrentScene()->RemoveRenderable2D(this);
        }
    };
}
