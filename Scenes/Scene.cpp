#include "Scene.hpp"

#include "../GameObject.hpp"
#include "../GameData.hpp"
#include "SFML/Graphics.hpp"

namespace mbgl {
    Scene::Scene(std::string name)
    : name(name) {}
    Scene::~Scene() {
        for (auto& gameObject : gameObjects)
            delete gameObject;
        gameObjects.clear();
    }

    void Scene::Load() {}
    void Scene::Close() {
        for (auto& gameObject : gameObjects)
            delete gameObject;
        gameObjects.clear();
    }

    void Scene::AddGameObject(GameObject* gameObject) {
        onStartSubs.push(gameObject);
    }
    void Scene::RemoveGameObject(GameObject* gameObject) { // this does NOT call delete
        onDestroySubs.push(gameObject);
    }

    void Scene::GameObjectStart() {
        while (!onStartSubs.empty()) { 
            GameObject* gameObject = onStartSubs.top();            
            gameObjects.insert(onStartSubs.top());

            gameObject->Start();

            onStartSubs.pop();
        }
    }

    void Scene::HandleEvents() {}
    void Scene::HandleInput() {
        sf::Event e;
        while (data->window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
                data->window.close();
        }
    }
    void Scene::Update() {
        for (auto& gameObject : gameObjects)
            gameObject->Update();
    }
    void Scene::FixedUpdate() {
        for (auto& gameObject : gameObjects)
            gameObject->FixedUpdate();
    }
    void Scene::Render() {
        data->window.clear();
        for (auto& gameObject : gameObjects)
            gameObject->Render();
        data->window.display();
    }

    void Scene::GameObjectDestroy() {
        while (!onDestroySubs.empty()) { 
            GameObject* gameObject = onDestroySubs.top();

            gameObject->OnDestroy();

            gameObjects.erase(gameObject);
            delete gameObject;
            onDestroySubs.pop();
        }
    }
}