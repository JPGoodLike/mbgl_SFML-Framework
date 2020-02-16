#include "Game.hpp"
#include "GlobalSettings.hpp"

#include <iostream>

using namespace mbgl;

int main() {
    Game game(Vector2<int>(c_screenWidth, c_screenHeight), c_gameTitle);
}