#pragma once //makes sure header is only included once

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics.hpp>
#include <memory>
#include "GameState.hpp"
#include "Game.hpp"

// mainmenu state inherits Game State
class mainmenu : public GameEngine::GameState 
{
    private:
    std::shared_ptr<Context> context;
    // sprites!
    sf::Text title;
    sf::Text play;
    sf::Text exit;
    sf::Text instructions;
    sf::Sprite sprite;

    bool isPlay;
    bool isExit;
    bool isInstructions;

    bool isPlaySelected;
    bool isExitSelected;
    bool isInstructionsSelected;

    public:
        mainmenu(std::shared_ptr<Context> &context);
        ~mainmenu() override; // checks that the method is overwriting method in base class

        void Init() override;
        void ProcessInput() override;
        void Update(sf::Time deltaTime) override;
        void Draw() override;
};