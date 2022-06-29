#pragma once

#include <memory>

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics.hpp>
#include "GameState.hpp"
#include "Game.hpp"

class gameover : public GameEngine::GameState
{
private:
    std::shared_ptr<Context> context;
    sf::Text endTitle;
    sf::Text endretry;
    sf::Text endexit;
    sf::Sprite endsprite;

    bool endretrySelected;
    bool endretryPressed;

    bool endexitSelected;
    bool endexitPressed;

public:
    gameover(std::shared_ptr<Context> &context);
    ~gameover();

    void Init() override;
    void ProcessInput() override;
    void Update(sf::Time deltaTime) override;
    void Draw() override;
};