#pragma once

#include "mbgl_Library/Events.cpp"

#include <vector>
#include <memory>
#include <unordered_map>

namespace mbgl {
    struct InputLayer {
        std::unordered_map<int, event<void()>> keys;
    };
    class InputManager {
    public:
        std::vector<InputLayer> inputLayers;
        int currentInputLayerIndex;
    };
}