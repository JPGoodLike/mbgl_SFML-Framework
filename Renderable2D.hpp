#pragma once

#include "Math/Transformable.hpp"
#include "SFML/Graphics.hpp"

namespace mbgl {
    class Renderable2D : public Transformable {
    public:
        sf::Sprite sprite;
        Renderable2D(vec3 position = vec3::Zero(), vec3 rotation = vec3::Zero(), vec3 scale = vec3::One());
        
    };
}