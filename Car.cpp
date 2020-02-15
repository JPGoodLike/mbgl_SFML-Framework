#include "Car.hpp"

#include <iostream>

using namespace std;

namespace mbgl {
    Car::Car(std::string name, float speed) 
    : GameObject(name), speed(speed) {}

    void Car::Start() {
        cout << "Car was created" << endl;
    }

    void Car::Update() {
        cout << speed << endl;
        q++;
        if (q == 3)
            Destroy(this);
    }

    void Car::OnDestroy() {
        cout << "Car was destroyed" << endl;
    }
}