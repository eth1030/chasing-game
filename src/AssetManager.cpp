#include "AssetManager.hpp"

GameEngine::AssetManager::AssetManager() 
{

}

GameEngine::AssetManager::~AssetManager() 
{

}

    void GameEngine::AssetManager::AddTexture(int id, const std::string &filePath, bool wantRepeated)
    {
        auto texture = std::make_unique<sf::Texture>();

        if(texture->loadFromFile(filePath))
        {
            texture->setRepeated(wantRepeated);
            textures [id] = std::move(texture);
        }
    }
    void GameEngine::AssetManager::AddFont(int id, const std::string &filePath)
    {
        auto font = std::make_unique<sf::Font>();

        if(font->loadFromFile(filePath))
        {
            fonts[id] = std::move(font);
        }
    }

    const sf::Texture &GameEngine::AssetManager::GetTexture(int id) const
    {
        return *(textures.at(id).get());
    }
    const sf::Font &GameEngine::AssetManager::GetFont(int id) const
    {
        return *(fonts.at(id).get());
    }