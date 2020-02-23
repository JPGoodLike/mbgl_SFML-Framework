#include "Transform.hpp"

#include "../GlobalSettings.hpp"

namespace mbgl {
    vec2i Transform::ToPointOnScreen(vec3 position, Transform* cameraT) {
        vec2 relativePos = position - cameraT->position;
        vec2i relativePosInPixels = (vec2i)(relativePos * c_pixelPerUnit);
        return vec2i(c_screenWidth/2 + relativePosInPixels.x, c_screenHeight/2 - relativePosInPixels.y);
    }
}