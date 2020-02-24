#include "Scene.hpp"

#include "GameObject.hpp"
#include "GameData.hpp"
#include "Math/Transformable.hpp"
#include "Renderable2D.hpp"
#include "Camera2D.hpp"
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
        if (data->mainCamera != nullptr) {
            delete data->mainCamera;
            data->mainCamera = nullptr;
        }
    }

    void Scene::AddGameObject(GameObject* gameObject) {
        onCreateSubs.push(gameObject);
    }
    void Scene::RemoveGameObject(GameObject* gameObject) { // this does NOT call delete
        onDestroySubs.push(gameObject);
    }

    void Scene::AddRenderable2D(Renderable2D* renderable) {
        renderables.insert(renderable);
    }
    void Scene::RemoveRenderable2D(Renderable2D* renderable) {
        renderables.erase(renderable);
    }

    void Scene::GameObjectCreate() {
        while (!onCreateSubs.empty()) { 
            GameObject* gameObject = onCreateSubs.front();            
            gameObjects.insert(onCreateSubs.front());

            gameObject->Init();
            gameObject->OnCreate();

            onCreateSubs.pop();
        }
    }

    void Scene::HandleEvents() {}
    void Scene::HandleInput() {
        data->inputManager.Key();
        sf::Event e;
        while (data->window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
                data->window.close();
                
            if (e.type == sf::Event::KeyPressed) {
                data->inputManager.KeyDown(e.key.code);
            }
            if (e.type == sf::Event::KeyReleased) {
                data->inputManager.KeyUp(e.key.code);
            }
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
        for (auto& renderable : renderables) {
            renderable->sprite.setPosition(Transformable::ToPointOnScreen(renderable->position, data->mainCamera));
            renderable->sprite.setRotation(renderable->rotation.z);
            renderable->sprite.setScale(renderable->scale);
            data->window.draw(renderable->sprite);
        }
        data->window.display();
    }

    void Scene::GameObjectDestroy() {
        while (!onDestroySubs.empty()) { 
            GameObject* gameObject = onDestroySubs.front();

            gameObject->OnDestroy();
            gameObject->Shutdown();

            gameObjects.erase(gameObject);
            delete gameObject;
            onDestroySubs.pop();
        }
    }
}