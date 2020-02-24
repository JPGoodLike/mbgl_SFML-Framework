#pragma once

#include "GameObject.hpp"
#include "OrthographicCamera.hpp"

namespace mbgl {
    class Camera2D : public GameObject, public OrthographicCamera {
    public:
        Camera2D(std::string name, vec3 position = vec3::Zero(), vec3 rotation = vec3::Zero(), vec3 scale = vec3::One());

        void Init() override;
        void Shutdown() override;
    };
}