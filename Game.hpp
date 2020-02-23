#pragma once

#include "SceneManager.hpp"

#include "Math/Vectors.hpp"

#include <string>

namespace mbgl {
    class Game {        
    public:
        Game(const Vector2<int>& windowSize, const std::string title);
        ~Game();

        void Run();
    };
}