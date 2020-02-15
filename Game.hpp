#pragma once

#include "SceneManager.hpp"

#include "mbgl_Library/Vectors.cpp"

#include <string>

namespace mbgl {
    class Game {        
    public:
        Game(const Vector2<int>& windowSize, const std::string title);
        ~Game();

        void Run();
    };
}