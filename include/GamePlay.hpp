#pragma once

#include <memory>
#include <array>
#include "Game.hpp"
#include "GameState.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include "Chaser.hpp"
// #include "Chased.hpp"
// #include "snek.hpp"

class GamePlay : public GameEngine::GameState
{
    private:
    std::shared_ptr<Context> context;
    sf::Sprite BACKGROUND;
    Chaser chaser;
    // Chased chased;
    std::array<sf::Sprite, 4> walls;
    sf::Vector2f chaserDirection;
    sf::Vector2f chasedDirection;
    sf::Time m_elapsedTime;
    sf::Sprite snek;
    // Chased chased;

    public:
        GamePlay(std::shared_ptr<Context> &context);
        ~GamePlay();

        void Init() override;
        void ProcessInput() override;
        void Update(sf::Time deltaTime) override;
        void Draw() override;
 };