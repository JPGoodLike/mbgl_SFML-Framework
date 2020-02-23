#pragma once

#include "Math/Transform.hpp"
#include "SFML/Graphics.hpp"

namespace mbgl {
    // struct PartDrawInfo {
    //     sf::Sprite sprite;
    //     Transform transform;
    //     PartDrawInfo(sf::Sprite sprite, Transform transform);
    // };

    class Renderable2D : public Transform {
    public:
        sf::Sprite sprite;
        Renderable2D(vec3 position = vec3::Zero(), vec3 rotation = vec3::Zero(), vec3 scale = vec3::Zero());
        
    };
}