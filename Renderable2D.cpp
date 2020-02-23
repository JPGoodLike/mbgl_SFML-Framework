#include "Renderable2D.hpp"

#include "GameData.hpp"

namespace mbgl {
    // PartDrawInfo::PartDrawInfo(sf::Sprite sprite, Transform transform) 
    // : sprite(sprite), transform(transform) {}

    Renderable2D::Renderable2D(vec3 position, vec3 rotation, vec3 scale)
    : Transform(position, rotation, scale) {}
}