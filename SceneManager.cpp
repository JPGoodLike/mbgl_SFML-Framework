#include "SceneManager.hpp"

namespace mbgl {

    void SceneManager::AddScene(std::string sceneName, Scene* scene) {
        scenes.emplace(std::make_pair(sceneName, std::unique_ptr<Scene>(scene)));
    }
    void SceneManager::RemoveScene(std::string sceneName) {
        scenes.erase(sceneName);
    }

    void SceneManager::LoadScene(std::string sceneName) {
        if (scenes.find(currentSceneName) != scenes.end())
            scenes[currentSceneName]->Close();
        currentSceneName = sceneName;
        scenes[sceneName]->Load();
    }
    std::unique_ptr<Scene>& SceneManager::GetCurrentScene() {
        return scenes[currentSceneName];
    }

}