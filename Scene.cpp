#include "Scene.hpp"

#include "GameObject.hpp"
#include "GameData.hpp"
#include "Math/Transformable.hpp"
#include "Renderable2D.hpp"
#include "RenderObject2D.hpp"
#include "Camera2D.hpp"
#include "SFML/Graphics.hpp"

#include <iostream>

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
        renderables.push_back(renderable);
    }
    void Scene::RemoveRenderable2D(Renderable2D* renderable) {
        renderables.erase(std::find(renderables.begin(), renderables.end(), renderable));
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
        data->inputManager.KeyUpdate();
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
        for (auto& gameObject : gameObjects) {
            if (gameObject->isActive)
                gameObject->Update();
        }
    }
    void Scene::FixedUpdate() {
        for (auto& gameObject : gameObjects) {
            if (gameObject->isActive)
                gameObject->FixedUpdate();
        }
    }
    void Scene::Render() {
        data->window.clear();
        if (wasRenderOrderChange) {
            std::sort(renderables.begin(), renderables.end(), Renderable2DComparator());
            wasRenderOrderChange = false;
        }
        for (auto& renderable : renderables) {
            if (!((RenderObject2D*)renderable)->isActive)
                continue;
            renderable->sprite.setPosition(Transformable::ToPointOnScreen(renderable->position, data->mainCamera));
            renderable->sprite.setRotation(renderable->rotation.z - data->mainCamera->rotation.z);
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

    bool Renderable2DComparator::operator() (const Renderable2D* self, const Renderable2D* other) const {
        return self->position.z > other->position.z;
    }
}