#pragma once

#include "mbgl_Library/Events.cpp"

#include "SFML/Graphics.hpp"

#include <vector>
#include <bitset>
#include <unordered_set>

namespace mbgl {
    struct KeyEvents {
        event<void()> OnKeyDown;
        event<void()> OnKeyUp;
        event<void()> OnKey;
    };

    const int c_inputLayerKeyQ = sf::Keyboard::KeyCount;

    class InputLayer {
    private:
        std::vector<KeyEvents> keys;

    public:
        InputLayer();

        // template <int keyQ>
        // InputLayer(std::array<sf::Keyboard::Key, keyQ>& keys) {
        //     this->keys.reserve(keyQ);
        //     for (auto& key : keys)
        //         this->keys.emplace(std::make_pair(key, KeyEvents()));
        // }

        void BindOnKeyDown(Callable<void()>& c, sf::Keyboard::Key keycode);
        void BindOnKeyUp(Callable<void()>& c, sf::Keyboard::Key keycode);
        void BindOnKey(Callable<void()>& c, sf::Keyboard::Key keycode);
        void UnbindOnKeyDown(Callable<void()>& c, sf::Keyboard::Key keycode);
        void UnbindOnKeyUp(Callable<void()>& c, sf::Keyboard::Key keycode);
        void UnbindOnKey(Callable<void()>& c, sf::Keyboard::Key keycode);

        void OnKeyDown(sf::Keyboard::Key keycode);
        void OnKeyUp(sf::Keyboard::Key keycode);
        void OnKey(sf::Keyboard::Key keycode);
    };

    const unsigned int c_inputManagerInputLayerQ = 1;

    class InputManager {
    public:
        InputManager();
        ~InputManager() = default;

        std::vector<InputLayer> inputLayers;
        std::unordered_set<unsigned int> activeLayers;

        std::unordered_set<sf::Keyboard::Key> heldKeys;
        std::bitset<c_inputLayerKeyQ> isKeyDownMask;

        void AddInputLayer();
        
        // template <int keyQ>
        // void AddInputLayer(std::array<sf::Keyboard::Key, keyQ>& keys) {
        //     inputLayers.emplace_back(keys);
        // }

        void ToggleInputLayer(unsigned int index, bool value);

        bool IsKeyDown(sf::Keyboard::Key keycode);
        void OnKeyDown(sf::Keyboard::Key keycode);
        void OnKeyUp(sf::Keyboard::Key keycode);
        void OnKey();
    };
}