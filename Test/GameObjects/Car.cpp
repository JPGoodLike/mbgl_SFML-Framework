#include "Car.hpp"

#include "Camera2D.hpp"

#include <iostream>

using namespace std;

namespace mbgl {
    Car::Car(std::string name, float speed, float angularSpeed) 
    : RenderObject2D(name), speed(speed), angularSpeed(angularSpeed) {
        d_CarToggleActive.Bind(this, &Car::CarToggleActive);

        sf::Texture& carTexture = data->assetManager.GetTexture("CarTexture");
        sprite.setTexture(carTexture);
        sprite.setOrigin(vec2(carTexture.getSize().x, carTexture.getSize().y) / 2);

        scale = vec3(0.1, 0.1, 1);
    }

    void Car::OnCreate() {
        InputLayer& il = data->inputManager.GetInputLayer(0);
        il.BindOnKeyDown(d_CarToggleActive, sf::Keyboard::T);
        cout << "Car was created" << endl;
    }

    void Car::Update() {
        InputManager& im = data->inputManager;
        float dt = data->time.deltaTime;
        if (im.IsKey(sf::Keyboard::W)) {
            position += direction * speed * dt;
            // data->mainCamera->position = position;
        }
        if (im.IsKey(sf::Keyboard::S)) {
            position -= direction * speed * dt;
            // data->mainCamera->position = position;
        }
        if (im.IsKey(sf::Keyboard::A)) {
            rotation.z -= angularSpeed * dt;
            // data->mainCamera->rotation.z -= angularSpeed * dt;
            direction = direction.Rotated(angularSpeed * dt);
        }
        if (im.IsKey(sf::Keyboard::D)) {
            rotation.z += angularSpeed * dt;
            // data->mainCamera->rotation.z += angularSpeed * dt;
            direction = direction.Rotated(-angularSpeed * dt);
        }
        
        if (im.IsKeyDown(sf::Keyboard::F)) {
            position.z = -1;
            data->sceneManager.GetCurrentScene()->wasRenderOrderChange = true;
        }
        if (im.IsKeyDown(sf::Keyboard::G)) {
            position.z = 1;
            data->sceneManager.GetCurrentScene()->wasRenderOrderChange = true;
        }
        
        if (im.IsKeyDown(sf::Keyboard::C)) {
            isCameraAttached = !isCameraAttached;
        }
        if (isCameraAttached) {
            data->mainCamera->position = position;
            data->mainCamera->rotation.z = rotation.z + 90;
        }
    }

    void Car::OnDestroy() {
        cout << "Car was destroyed" << endl;
    }

    void Car::CarToggleActive() {
        SetActive(!IsActive());
    }
}