#include "../../Scenes.hpp"

#include "../GameObjects/Car.hpp"
#include "../GameObjects/TestObject.cpp"

namespace mbgl {
    // Test Scene
    void TestScene::Load() {
        // Car* car = Instantiate(new Car("Some Car", 30));
        Instantiate(new TestObject("Test Object"));
    }
    // End of Test Scene
}