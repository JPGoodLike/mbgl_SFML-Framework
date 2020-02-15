#pragma once

#include "GameObject.hpp"

#include <iostream>

namespace mbgl {
    class Car : public GameObject {
    public:
        float speed;
        int q = 0;

        Car(std::string name, float speed);

        void Start() override;
        void Update() override;
        void OnDestroy() override;
    };
}