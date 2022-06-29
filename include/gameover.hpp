#pragma once

#include <memory>

#include <SFML/Graphics/Text.hpp>

#include "GameState.hpp"
#include "Game.hpp"

class gameover : public GameEngine::GameState
{
private:
    std::shared_ptr<Context> context;
    sf::Text m_gameOverTitle;
    sf::Text m_retryButton;
    sf::Text m_exitButton;

    bool m_isRetryButtonSelected;
    bool m_isRetryButtonPressed;

    bool m_isExitButtonSelected;
    bool m_isExitButtonPressed;

public:
    gameover(std::shared_ptr<Context> &context);
    ~gameover();

    void Init() override;
    void ProcessInput() override;
    void Update(sf::Time deltaTime) override;
    void Draw() override;
};