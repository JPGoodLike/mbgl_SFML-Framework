#pragma once

#include "Scene.hpp"

namespace mbgl {
    class TestScene : public Scene {
    public:
        TestScene(std::string name) : Scene(name) {}
        void Load() override;
    };
}