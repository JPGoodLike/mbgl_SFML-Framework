#include "InputManager.hpp"

namespace mbgl {
    // Input Layer
    InputLayer::InputLayer() {
        keys.reserve(sf::Keyboard::KeyCount);
        for (int i = sf::Keyboard::A; i < sf::Keyboard::KeyCount; i++) {
            keys.emplace_back();
        }
    }


    void InputLayer::BindOnKeyDown(Callable<void()>& c, sf::Keyboard::Key keycode) {
        keys[keycode].OnKeyDown += c;
    }
    void InputLayer::BindOnKeyUp(Callable<void()>& c, sf::Keyboard::Key keycode) {
        keys[keycode].OnKeyUp += c;
    }
    void InputLayer::BindOnKey(Callable<void()>& c, sf::Keyboard::Key keycode) {
        keys[keycode].OnKey += c;
    }
    void InputLayer::UnbindOnKeyDown(Callable<void()>& c, sf::Keyboard::Key keycode) {
        keys[keycode].OnKeyDown -= c;
    }
    void InputLayer::UnbindOnKeyUp(Callable<void()>& c, sf::Keyboard::Key keycode) {
        keys[keycode].OnKeyUp -= c;
    }
    void InputLayer::UnbindOnKey(Callable<void()>& c, sf::Keyboard::Key keycode) {
        keys[keycode].OnKey -= c;
    }

    void InputLayer::OnKeyDown(sf::Keyboard::Key keycode) {
        keys[keycode].OnKeyDown();
    }
    void InputLayer::OnKeyUp(sf::Keyboard::Key keycode) {
        keys[keycode].OnKeyUp();
    }
    void InputLayer::OnKey(sf::Keyboard::Key keycode) {
        keys[keycode].OnKey();
    }

    // Input Manager
    InputManager::InputManager() {
        inputLayers.reserve(c_inputManagerInputLayerQ);
        heldKeys.reserve(sf::Keyboard::KeyCount);
    }

    void InputManager::AddInputLayer() {
        inputLayers.emplace_back();
    }

    void InputManager::ToggleInputLayer(unsigned int index, bool value) {
        if (value) {
            activeLayers.insert(index);
        } else 
            activeLayers.erase(index);
    }

    bool InputManager::IsKeyDown(sf::Keyboard::Key keycode) {
        if ((int)keycode > -1 && (int)keycode < sf::Keyboard::KeyCount)
            return isKeyDownMask[(int)keycode];
        return false;
    }

    void InputManager::OnKeyDown(sf::Keyboard::Key keycode) {
        if ((int)keycode > -1 && (int)keycode < sf::Keyboard::KeyCount) {
            isKeyDownMask[keycode] = true;
            heldKeys.insert(keycode);
            for (auto& layerI : activeLayers) {
                inputLayers[layerI].OnKeyDown(keycode);
            }
        }
    }

    void InputManager::OnKeyUp(sf::Keyboard::Key keycode) {
        if ((int)keycode > -1 && (int)keycode < sf::Keyboard::KeyCount) {
            isKeyDownMask[keycode] = false;
            heldKeys.erase(keycode);
            for (auto& layerI : activeLayers) {
                inputLayers[layerI].OnKeyUp(keycode);
            }
        }
    }

    void InputManager::OnKey() {
        for (auto& layerI : activeLayers) {
            for (auto& keycode : heldKeys)
                inputLayers[layerI].OnKey(keycode);
        }
    }
}