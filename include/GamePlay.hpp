#pragma once

#include <memory>
#include <array>
#include "Game.hpp"
#include "GameState.hpp"
#include <SFML/Graphics/Sprite.hpp>
#include "Snake.hpp"

class GamePlay : public GameEngine::GameState
{
    private:
    std::shared_ptr<Context> context;
    sf::Sprite BACKGROUND;
    Snake m_snake;
    std::array<sf::Sprite, 4> walls;

    sf::Vector2f m_snakeDirection;
    sf::Time m_elapsedTime;
    sf::Sprite snek;

    public:
        GamePlay(std::shared_ptr<Context> &context);
        ~GamePlay();

        void Init() override;
        void ProcessInput() override;
        void Update(sf::Time deltaTime) override;
        void Draw() override;
        void Pause() override;
        void Start() override;
 };