#pragma once

#include "Scene.hpp"

#include <string>
#include <map>
#include <memory>

namespace mbgl {
    class SceneManager {
    public:
        SceneManager() = default;
        ~SceneManager() = default;

        std::map<std::string, std::unique_ptr<Scene>> scenes;
        std::string currentSceneName = "";

        void AddScene(std::string sceneName, Scene* scene);
        void RemoveScene(std::string sceneName);

        void LoadScene(std::string sceneName);
        std::unique_ptr<Scene>& GetCurrentScene();
    };
}

