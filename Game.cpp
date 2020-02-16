#include "Game.hpp"

#include "GameData.hpp"
#include "Scenes/Scenes.hpp"

#include <array>

namespace mbgl {
    std::unique_ptr<GameData> data = std::make_unique<GameData>();

    Game::Game(const Vector2<int>& windowSize, const std::string title) {
        data->window.create( sf::VideoMode(windowSize.x, windowSize.y), title, sf::Style::Close);

        Run();
    }
    Game::~Game() = default;

    void Game::Run() {
        // Load scene manager 
        SceneManager& sceneManager = data->sceneManager;

        sceneManager.AddScene("TestScene", new TestScene("TestScene"));
        sceneManager.LoadScene("TestScene");

        // Load input manager
        InputManager& inputManager = data->inputManager;
        inputManager.AddInputLayer<4>(std::array<char, 4>() = {'w', 'a', 's', 'd'});
        inputManager.layerMask.none();
        inputManager.layerMask[0] = true;

        // Game Loop
        float elapsedTime = 0;
        while (data->window.isOpen()) {
            std::unique_ptr<Scene>& currentScene = sceneManager.GetCurrentScene();

            data->time.ResetDeltaTime();

            currentScene->GameObjectStart();

            currentScene->HandleEvents();
            currentScene->HandleInput();

            data->time.UpdateDeltaTime();
            elapsedTime += data->time.deltaTime;
            data->time.deltaTime = data->time.fixedDeltaTime;
            while (elapsedTime >= data->time.fixedDeltaTime) {
                currentScene->FixedUpdate();
                elapsedTime -= data->time.fixedDeltaTime;
            }

            data->time.UpdateDeltaTime();
            currentScene->Update();
            currentScene->Render();

            currentScene->GameObjectDestroy();
        }
    }
}