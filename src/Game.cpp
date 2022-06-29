#include "Game.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Window/Event.hpp>
#include "mainmenu.hpp"

Game::Game() : context(std::make_shared<Context>())
{
    context->window->create(sf::VideoMode(1000, 800), "Predator & Prey", sf::Style::Close);
    context->states->Add(std::make_unique<mainmenu>(context));
}

Game::~Game() 
{

}

void Game::Run()
{
 sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Red);

    sf::Clock clock;
    sf::Time timeSinceLastFrame = sf::Time::Zero;
    // }
    while (context->window->isOpen())
    {
        timeSinceLastFrame += clock.restart();

        while (timeSinceLastFrame > fps)
        {
            timeSinceLastFrame -= fps;

            context->states->ProcessStateChange();
            context->states->GetCurrent()->ProcessInput();
            context->states->GetCurrent()->Update(fps);
            context->states->GetCurrent()->Draw();
        }
    }
}