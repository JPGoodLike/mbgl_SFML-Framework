#include "Scenes.hpp"

#include "../Car.hpp"
#include "../InputManager.hpp"

namespace mbgl {
    // Test Scene
    void TestScene::Load() {
        Car* car = Instantiate(new Car("Some Car", 30));
    }
    // End of Test Scene
}