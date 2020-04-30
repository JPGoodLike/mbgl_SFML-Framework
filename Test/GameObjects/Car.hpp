#pragma once

#include "RenderObject2D.hpp"

#include <iostream>

namespace mbgl {
    class Car : public RenderObject2D {
    public:
        float speed;
        float angularSpeed;
        vec2 direction = vec2(1, 0);
        bool isCameraAttached = false;

        Car(std::string name, float speed, float angularSpeed);

        void OnCreate() override;
        void Update() override;
        void OnDestroy() override;

        void CarToggleActive();
        delegate<void(), Car> d_CarToggleActive;
    };
}