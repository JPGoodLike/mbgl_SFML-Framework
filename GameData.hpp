#pragma once

#include "AssetManager.hpp"
#include "SceneManager.hpp"
#include "InputManager.hpp"
#include "Time.hpp"
#include "SFML/Graphics.hpp"
#include "OrthographicCamera.hpp"

#include <memory>


namespace mbgl {
    struct GameData {
        AssetManager assetManager;
        SceneManager sceneManager;
        InputManager inputManager;
        sf::RenderWindow window;
        Time time;
        OrthographicCamera* mainCamera = nullptr;
    };

    extern std::unique_ptr<GameData> data; // should be defided in Game.cpp
}