#include "Game.hpp"

#include "GameData.hpp"
#include "Scenes/Scenes.hpp"

namespace mbgl {
    std::unique_ptr<GameData> data = std::make_unique<GameData>();

    Game::Game(const Vector2<int>& windowSize, const std::string title) {
        data->window.create( sf::VideoMode(windowSize.x, windowSize.y), title, sf::Style::Close);

        Run();
    }
    Game::~Game() = default;

    void Game::Run() {
        SceneManager& sceneManager = data->sceneManager;

        TestScene* testScene = new TestScene("TestScene");
        sceneManager.AddScene(testScene->name, testScene);
        sceneManager.LoadScene("TestScene");
        
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