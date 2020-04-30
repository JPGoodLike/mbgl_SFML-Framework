#pragma once

#include "GameData.hpp"

#include <string>

namespace mbgl {
    class GameObject {
    private:
        bool isActive = true;

    protected:
        virtual void Init();
        virtual void Shutdown();

        virtual void OnEnable();
        virtual void OnDisable();

        virtual void OnCreate();
        virtual void Update();
        virtual void FixedUpdate();
        virtual void OnDestroy();

        friend class Scene;
    public:
        std::string name;

        GameObject(std::string name="GameObject");
        virtual ~GameObject();

        bool IsActive();
        void SetActive(bool state);
    };

    // add gameObject to scene 
    // (made trough function to avoid circular dependency between Scene and GameObject classes)
    // because it's template, the implementation in the header file
    template <typename T>
    T* Instantiate(T* gameObject) { 
        data->sceneManager.GetCurrentScene()->AddGameObject(gameObject);
        return gameObject;
    }

    template <typename T>
    void Destroy(T* gameObject) { 
        data->sceneManager.GetCurrentScene()->RemoveGameObject(gameObject);
    }
}