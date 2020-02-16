#pragma once

#include "SceneManager.hpp"
#include "InputManager.hpp"
#include "Time.hpp"
#include "SFML/Graphics.hpp"

#include <memory>


namespace mbgl {
    struct GameData {
        SceneManager sceneManager;
        InputManager inputManager;
        sf::RenderWindow window;
        Time time;
    };

    extern std::unique_ptr<GameData> data; // should be defided in Game.cpp
}