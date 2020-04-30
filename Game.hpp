#pragma once

#include "SceneManager.hpp"

#include "Math/Vectors.hpp"

#include <string>

namespace mbgl {
    class InputManager;
    class SceneManager;
    
    class Game {        
    public:
        Game(const Vector2<int>& windowSize, const std::string title);
        ~Game();

        void InputInit(InputManager& inputManager);
        void ScenesInit(SceneManager& sceneManager);

        void Run();
    };
}