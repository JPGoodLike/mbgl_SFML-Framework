#include "SFML/Graphics.hpp"

namespace mbgl {
    class Time {
    private:
        float frameStartTime = 0;
        float timeBetFrames = 0;

    public:
        sf::Clock time;
        float deltaTime = 0;

        float fixedDeltaTime = 1.0f / 30;

        void ResetDeltaTime() {
            float currentTime = time.getElapsedTime().asSeconds();
            timeBetFrames = currentTime - frameStartTime;
            deltaTime = timeBetFrames;
            frameStartTime = currentTime;
        }

        void UpdateDeltaTime() {
            float currentTime = time.getElapsedTime().asSeconds();
            deltaTime = timeBetFrames + (currentTime - frameStartTime);
        }
    };
}