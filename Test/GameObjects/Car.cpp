#include "Car.hpp"

#include "Camera2D.hpp"

#include <iostream>

using namespace std;

namespace mbgl {
    Car::Car(std::string name, float speed, float angularSpeed) 
    : RenderObject2D(name), speed(speed), angularSpeed(angularSpeed) {
        // d_CarKeyPressed.Bind(this, &Car::CarKeyPressed);
        // d_CarKeyReleased.Bind(this, &Car::CarKeyReleased);
        // d_CarKeyHold.Bind(this, &Car::CarKeyHold);

        sf::Texture& carTexture = data->assetManager.GetTexture("CarTexture");
        sprite.setTexture(carTexture);
        sprite.setOrigin(vec2(carTexture.getSize().x, carTexture.getSize().y) / 2);

        scale = vec3(0.1, 0.1, 1);
    }

    void Car::OnCreate() {
        InputLayer& il = data->inputManager.inputLayers[0];
        // il.BindOnKeyDown(d_CarKeyPressed, sf::Keyboard::A);
        // il.BindOnKeyUp(d_CarKeyReleased, sf::Keyboard::A);
        // il.BindOnKey(d_CarKeyHold, sf::Keyboard::A);
        cout << "Car was created" << endl;
    }

    void Car::Update() {
        InputManager& im = data->inputManager;
        float dt = data->time.deltaTime;
        if (im.IsKeyDown(sf::Keyboard::W)) {
            position += direction * speed * dt;
            data->mainCamera->position = position;
        }
        if (im.IsKeyDown(sf::Keyboard::S)) {
            position -= direction * speed * dt;
            data->mainCamera->position = position;
        }
        if (im.IsKeyDown(sf::Keyboard::A)) {
            rotation.z -= angularSpeed * dt;
            direction = direction.Rotated(angularSpeed * dt);
        }
        if (im.IsKeyDown(sf::Keyboard::D)) {
            rotation.z += angularSpeed * dt;
            direction = direction.Rotated(-angularSpeed * dt);
        }
    }

    void Car::OnDestroy() {
        cout << "Car was destroyed" << endl;
    }

    // void Car::CarKeyPressed() {
    //     std::cout << "Key pressed from car" << endl;
    // }
    // void Car::CarKeyReleased() {
    //     std::cout << "Key released from car" << endl;
    // }
    // void Car::CarKeyHold() {
    //     std::cout << "Key hold from car" << endl;
    // }
}