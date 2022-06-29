#pragma once

#include <memory>
#include <SFML/Graphics/RenderWindow.hpp>
#include "AssetManager.hpp"
#include "StateManager.hpp"

enum AssetID
{
    font = 0,
    my,
    background,
    CHASER,
    s,
    BORDER,
    sad,
    CHASED
};

struct Context 
{
    std::unique_ptr<GameEngine::AssetManager> assets;
    std::unique_ptr<GameEngine::StateManager> states;
    std::unique_ptr<sf::RenderWindow> window;

    Context()
    {
        assets = std::make_unique<GameEngine::AssetManager>();
        states = std::make_unique<GameEngine::StateManager>();
        window = std::make_unique<sf::RenderWindow>();
    }

};

class Game 
{

private:
    std::shared_ptr<Context> context;
    const sf::Time fps = sf::seconds(1.f/60.f);

public:
    Game();
    ~Game();

    void Run();
};