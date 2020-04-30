#include "Transformable.hpp"

#include "GlobalSettings.hpp"
#include "GameData.hpp"

namespace mbgl {
    vec2i Transformable::ToPointOnScreen(vec3 position, Transformable* cameraT) {
        vec2 relativePos = position - cameraT->position;
        relativePos = relativePos.Rotated(cameraT->rotation.z);
        vec2i relativePosInPixels = (vec2i)(relativePos * c_pixelPerUnit);
        vec2u screenSize = data->window.getSize();
        return vec2i(screenSize.x/2 + relativePosInPixels.x, screenSize.y/2 - relativePosInPixels.y);
    }
}