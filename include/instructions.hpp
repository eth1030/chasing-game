#pragma once

#include <memory>

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics.hpp>
#include "GameState.hpp"
#include "mainmenu.hpp"

class instructions : public GameEngine::GameState
{
private:
    std::shared_ptr<Context> context;
    // sf::Text inTitle;
    sf::Sprite insprite;

    bool enterpressed;

public:
    instructions(std::shared_ptr<Context> &context);
    ~instructions();

    void Init() override;
    void ProcessInput() override;
    void Update(sf::Time deltaTime) override;
    void Draw() override;
};