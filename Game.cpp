#include "Game.hpp"

#include "GameData.hpp"

#include <array>

namespace mbgl {
    std::unique_ptr<GameData> data = std::make_unique<GameData>();

    Game::Game(const Vector2<int>& windowSize, const std::string title) {
        data->window.create( sf::VideoMode(windowSize.x, windowSize.y), title, sf::Style::Close);

        Run();
    }
    Game::~Game() = default;

    void Game::Run() {
        // Load input manager
        InputManager& inputManager = data->inputManager;
        data->window.setKeyRepeatEnabled(false);
        InputInit(inputManager);
        
        // Load scene manager 
        SceneManager& sceneManager = data->sceneManager;
        ScenesInit(sceneManager);

        // Game Loop
        float elapsedTime = 0;
        data->time.ResetDeltaTime();
        while (data->window.isOpen()) {
            std::unique_ptr<Scene>& currentScene = sceneManager.GetCurrentScene();

            data->time.ResetDeltaTime();

            currentScene->GameObjectCreate();

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