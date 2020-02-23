#pragma once

#include "../../RenderObject2D.hpp"

#include <iostream>

namespace mbgl {
    class Car : public RenderObject2D {
    public:
        float speed;
        float angularSpeed;
        vec2 direction = vec2(1, 0);

        Car(std::string name, float speed, float angularSpeed);

        void Start() override;
        void Update() override;
        void OnDestroy() override;

        void CarKeyPressed();
        delegate<void(), Car> d_CarKeyPressed;
        void CarKeyReleased();
        delegate<void(), Car> d_CarKeyReleased;
        void CarKeyHold();
        delegate<void(), Car> d_CarKeyHold;
    };
}