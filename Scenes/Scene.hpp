#pragma once

#include <string>
#include <memory>
#include <stack>
#include <unordered_set>


namespace mbgl {
    class GameObject;
    class GameData;

    class Scene {
    protected:
        std::unordered_set<GameObject*> gameObjects;

        std::stack<GameObject*> onStartSubs;
        std::stack<GameObject*> onDestroySubs;

        
    public:
        std::string name;

        Scene(std::string name);        
        ~Scene();

        virtual void Load();
        virtual void Close();

        virtual void AddGameObject(GameObject* gameObject);
        virtual void RemoveGameObject(GameObject* gameObject);

        virtual void GameObjectStart();

        virtual void HandleEvents();
        virtual void HandleInput();
        virtual void Update();
        virtual void FixedUpdate();
        virtual void Render();

        virtual void GameObjectDestroy();
    }; 
}