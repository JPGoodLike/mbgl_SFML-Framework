#include "Scenes.hpp"

#include "Test/GameObjects/Car.hpp"
#include "Test/GameObjects/Box.hpp"
#include "Test/GameObjects/TestObject.cpp"
#include "Camera2D.hpp"

namespace mbgl {
    void TestScene::Load() {
        data->assetManager.LoadTextures<2>(std::array<TextureInfo, 2> {
            TextureInfo("CarTexture", "../Test/Textures/CarSpriteTexture.png"),
            TextureInfo("BoxTexture", "../Test/Textures/BoxSpriteTexture.png")
        });

        Instantiate(new Camera2D("Main Camera"));
        Instantiate(new Car("Some Car", 5, 100));
        Instantiate(new Box("Some Box", vec2(5, 0)));
        Instantiate(new Box("Another Box", vec2(1, 0)));
        
        // Instantiate(new TestObject("Test Object"));
    }
}