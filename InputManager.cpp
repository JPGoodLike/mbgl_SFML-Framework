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

    void InputLayer::BindOnAnyKeyDown(Callable<void(sf::Keyboard::Key)>& c) {
        OnAnyKeyDown += c;
    }
    void InputLayer::BindOnAnyKeyUp(Callable<void(sf::Keyboard::Key)>& c) {
        OnAnyKeyUp += c;
    }
    void InputLayer::BindOnAnyKey(Callable<void(sf::Keyboard::Key)>& c) {
        OnAnyKey += c;
    }
    void InputLayer::UnbindOnAnyKeyDown(Callable<void(sf::Keyboard::Key)>& c) {
        OnAnyKeyDown -= c;
    }
    void InputLayer::UnbindOnAnyKeyUp(Callable<void(sf::Keyboard::Key)>& c) {
        OnAnyKeyUp -= c;
    }
    void InputLayer::UnbindOnAnyKey(Callable<void(sf::Keyboard::Key)>& c) {
        OnAnyKey -= c;
    }


    void InputLayer::OnKeyDown(sf::Keyboard::Key keycode) {
        keys[keycode].OnKeyDown();
        OnAnyKeyDown(keycode);
    }
    void InputLayer::OnKeyUp(sf::Keyboard::Key keycode) {
        keys[keycode].OnKeyUp();
        OnAnyKeyUp(keycode);
    }
    void InputLayer::OnKey(sf::Keyboard::Key keycode) {
        keys[keycode].OnKey();
        OnAnyKey(keycode);
    }

    // Input Manager
    InputManager::InputManager() {
        inputLayers.reserve(c_inputManagerInputLayerQ);
        heldKeys.reserve(sf::Keyboard::KeyCount);
    }

    void InputManager::AddInputLayer() {
        inputLayers.emplace_back();
    }

    InputLayer& InputManager::GetInputLayer(const unsigned int index) {
        return inputLayers[index];
    }
    const std::unordered_set<unsigned int>& InputManager::GetActiveLayers() const {
        return activeLayers;
    }

    void InputManager::ToggleInputLayer(unsigned int index, bool value) {
        if (value) {
            activeLayers.insert(index);
        } else 
            activeLayers.erase(index);
    }

    bool InputManager::IsKeyDown(sf::Keyboard::Key keycode) const {
        if ((int)keycode > -1 && (int)keycode < sf::Keyboard::KeyCount)
            return isKeyDownMask[(int)keycode];
        return false;
    }
    bool InputManager::IsKeyUp(sf::Keyboard::Key keycode) const {
        if ((int)keycode > -1 && (int)keycode < sf::Keyboard::KeyCount)
            return isKeyUpMask[(int)keycode];
        return false;
    }
    bool InputManager::IsKey(sf::Keyboard::Key keycode) const {
        if ((int)keycode > -1 && (int)keycode < sf::Keyboard::KeyCount)
            return isKeyMask[(int)keycode];
        return false;
    }

    const std::unordered_set<sf::Keyboard::Key>& InputManager::HeldKeys() const {
        return heldKeys;
    }

    void InputManager::KeyDown(sf::Keyboard::Key keycode) {
        if ((int)keycode > -1 && (int)keycode < sf::Keyboard::KeyCount) {
            isKeyDownMask[keycode] = true;
            isKeyMask[keycode] = true;
            heldKeys.insert(keycode);
            for (auto& layerI : activeLayers) {
                inputLayers[layerI].OnKeyDown(keycode);
            }
        }
    }

    void InputManager::KeyUp(sf::Keyboard::Key keycode) {
        if ((int)keycode > -1 && (int)keycode < sf::Keyboard::KeyCount) {
            isKeyMask[keycode] = false;
            isKeyUpMask[keycode] = true;
            heldKeys.erase(keycode);
            for (auto& layerI : activeLayers) {
                inputLayers[layerI].OnKeyUp(keycode);
            }
        }
    }

    void InputManager::KeyUpdate() {
        isKeyDownMask = 0;
        isKeyUpMask = 0;
        for (auto& layerI : activeLayers) {
            for (auto& keycode : heldKeys)
                inputLayers[layerI].OnKey(keycode);
        }
    }
}