#include "Renderable2D.hpp"

#include "GameData.hpp"

namespace mbgl {
    Renderable2D::Renderable2D(vec3 position, vec3 rotation, vec3 scale)
    : Transformable(position, rotation, scale) {}
}