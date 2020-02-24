#pragma once

#include "AssetManager.hpp"
#include "SceneManager.hpp"
#include "InputManager.hpp"
#include "Time.hpp"
#include "SFML/Graphics.hpp"

#include <memory>


namespace mbgl {
    class Camera2D;
    
    struct GameData {
        AssetManager assetManager;
        SceneManager sceneManager;
        InputManager inputManager;
        sf::RenderWindow window;
        Time time;
        Camera2D* mainCamera = nullptr;
    };

    extern std::unique_ptr<GameData> data; // should be defided in Game.cpp
}