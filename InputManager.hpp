#pragma once

#include "mbgl_Library/Events.cpp"
#include "GlobalSettings.hpp"

#include <vector>
#include <memory>
#include <bitset>
#include <unordered_map>

namespace mbgl {
    class InputLayer {
    public:
        std::unordered_map<int, event<void()>> keys;
        std::bitset<c_bitsetSize> isKeyDownMask;

        template <int keyQ>
        InputLayer(std::array<char, keyQ>& keys) {
            this->keys.reserve(keyQ);
            for (auto& key : keys)
                this->keys.emplace(std::make_pair(key, event<void()> e));
        }
    };

    class InputManager {
    public:
        InputManager() = default;
        ~InputManager() = default;

        std::vector<InputLayer> inputLayers;
        std::bitset<c_bitsetSize> layerMask;

        template <int keyQ>
        void AddInputLayer(std::array<char, keyQ>& keys) {
            inputLayers.emplace_back(keys);
        }

        void OnKeyDown(int keycode);
        void OnKeyUp(int keycode);
        void OnKey(int keycode);
    };
}