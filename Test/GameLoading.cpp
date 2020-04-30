#include "Game.hpp"

#include "GameData.hpp"
#include "Test/Scenes/Scenes.hpp"

namespace mbgl {
    void Game::InputInit(InputManager& inputManager) {
        // Load input manager
        inputManager.AddInputLayer();
        inputManager.ToggleInputLayer(0, true);
    }

    void Game::ScenesInit(SceneManager& sceneManager) {        
        // Load scene manager 
        sceneManager.AddScene("TestScene", new TestScene("TestScene"));
        sceneManager.LoadScene("TestScene");
    }
}