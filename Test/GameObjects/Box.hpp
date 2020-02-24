#pragma once

#include "RenderObject2D.hpp"

#include <iostream>

namespace mbgl {
    class Box : public RenderObject2D {
    public:
        Box(std::string name, vec3 position = vec3::Zero()) 
        : RenderObject2D(name, position) {
            sf::Texture& boxTexture = data->assetManager.GetTexture("BoxTexture");
            sprite.setTexture(boxTexture);
            sprite.setOrigin(vec2(boxTexture.getSize().x, boxTexture.getSize().y) / 2);

            scale = vec3(0.1, 0.1, 1);
        }

        void OnCreate() override {
            std::cout << "Box was created" << std::endl;
        }
    };
}