#pragma once

#include "SceneManager.hpp"
#include "Time.hpp"
#include "SFML/Graphics.hpp"

#include <memory>


namespace mbgl {
    struct GameData {
        SceneManager sceneManager;
        sf::RenderWindow window;
        Time time;
    };

    extern std::unique_ptr<GameData> data; // should be defided in Game.cpp
}