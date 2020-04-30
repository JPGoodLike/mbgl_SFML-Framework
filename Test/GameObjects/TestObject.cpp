#include "GameObject.hpp"

#include <iostream>

namespace mbgl {
    class TestObject : public GameObject {
    public:
        TestObject(std::string name)
        : GameObject(name) {
            d_LogIsButtonPressed.Bind(this, &TestObject::LogIsButtonPressed);
        }

        void OnCreate() override {
            data->inputManager.GetInputLayer(0).BindOnKeyDown(d_LogIsButtonPressed, sf::Keyboard::A);
        }

        void LogIsButtonPressed() {
            std::cout << data->inputManager.IsKeyDown(sf::Keyboard::H) << std::endl;
        }
        delegate<void(), TestObject> d_LogIsButtonPressed;
    };
}