#pragma once

#include <string>
#include <memory>
#include <queue>
#include <vector>
#include <unordered_set>


namespace mbgl {
    class GameObject;
    class GameData;
    class Renderable2D;

    struct Renderable2DComparator {
        bool operator() (const Renderable2D* self, const Renderable2D* other) const;
    };

    class Scene {
    protected:
        std::unordered_set<GameObject*> gameObjects;
        std::vector<Renderable2D*> renderables;        

        std::queue<GameObject*> onCreateSubs;
        std::queue<GameObject*> onDestroySubs;
        
    public:
        std::string name;

        bool wasRenderOrderChange = false;

        Scene(std::string name);        
        ~Scene();

        virtual void Load();
        virtual void Close();

        virtual void AddGameObject(GameObject* gameObject);
        virtual void RemoveGameObject(GameObject* gameObject);

        virtual void AddRenderable2D(Renderable2D* renderable); // use only in Init() method
        virtual void RemoveRenderable2D(Renderable2D* renderable); // use only in Shutdown() method

        virtual void GameObjectCreate();

        virtual void HandleEvents();
        virtual void HandleInput();
        virtual void Update();
        virtual void FixedUpdate();
        virtual void Render();

        virtual void GameObjectDestroy();
    }; 
}