#include "Car.hpp"

#include <iostream>

using namespace std;

namespace mbgl {
    Car::Car(std::string name, float speed) 
    : GameObject(name), speed(speed) {
        d_CarKeyPressed.Bind(this, &Car::CarKeyPressed);
        d_CarKeyReleased.Bind(this, &Car::CarKeyReleased);
        d_CarKeyHold.Bind(this, &Car::CarKeyHold);
    }

    void Car::Start() {
        InputLayer& il = data->inputManager.inputLayers[0];
        il.BindOnKeyDown(d_CarKeyPressed, sf::Keyboard::A);
        il.BindOnKeyUp(d_CarKeyReleased, sf::Keyboard::A);
        il.BindOnKey(d_CarKeyHold, sf::Keyboard::A);
        cout << "Car was created" << endl;
    }

    void Car::Update() {
        // cout << speed << endl;
        // q++;
        // if (q == 3)
        //     Destroy(this);
    }

    void Car::OnDestroy() {
        cout << "Car was destroyed" << endl;
    }

    void Car::CarKeyPressed() {
        std::cout << "Key pressed from car" << endl;
    }
    void Car::CarKeyReleased() {
        std::cout << "Key released from car" << endl;
    }
    void Car::CarKeyHold() {
        std::cout << "Key hold from car" << endl;
    }
}