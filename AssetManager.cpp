#include "AssetManager.hpp"

namespace mbgl {
    TextureInfo::TextureInfo(std::string name, std::string path) 
    : name(name), path(path) {}

    sf::Texture& AssetManager::GetTexture(std::string textureName) {
        return textures[textureName];
    }
}