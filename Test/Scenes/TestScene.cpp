#include "../../Scenes.hpp"

#include "../GameObjects/Car.hpp"
#include "../GameObjects/TestObject.cpp"
#include "../../Camera2D.hpp"

namespace mbgl {
    // Test Scene
    void TestScene::Load() {
        data->assetManager.LoadTextures<1>(std::array<TextureInfo, 1> {
            TextureInfo("CarSprite", "../Test/Textures/CarSprite.png")
        });

        Instantiate(new Car("Some Car", 5, 100));
        data->mainCamera = Instantiate(new Camera2D("Main Camera"));
        // Instantiate(new TestObject("Test Object"));
    }
    // End of Test Scene
}