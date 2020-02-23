#pragma once

#include "SFML/Graphics.hpp"

#include <unordered_map>

namespace mbgl {
    struct TextureInfo {
        std::string name;
        std::string path;
        TextureInfo(std::string name, std::string path);
    };

    class AssetManager {
    private:
        std::unordered_map<std::string, sf::Texture> textures;
    public:
        template <int q>
        void LoadTextures(std::array<TextureInfo, q> textureData) {
            for (auto& texture : textureData) {                
                textures.insert(std::make_pair(texture.name, sf::Texture()));
                textures[texture.name].loadFromFile(texture.path);
            }
        }
        template <int q>
        void RemoveTextures(std::array<std::string, q> textureNames) {
            for (auto& textureName : textureNames) {
                textures.erase(textureName);
            }
        }

        sf::Texture& GetTexture(std::string textureName);

    };
}
