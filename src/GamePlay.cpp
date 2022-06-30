#include "GamePlay.hpp"
#include "Chaser.hpp"
#include <SFML/Window/Event.hpp>
#include "gameover.hpp"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Drawable.hpp>

GamePlay::GamePlay(std::shared_ptr<Context> &context)
    : context(context), chaserDirection({0.f, 0.f}), m_elapsedTime(sf::Time::Zero)
{

}

GamePlay::~GamePlay()
{

}

void GamePlay::Init()
{
    context->assets->AddTexture(background, "assets/textures/back.PNG");
    BACKGROUND.setTexture(context->assets->GetTexture(background));
    BACKGROUND.setTextureRect(context->window->getViewport(context->window->getDefaultView()));

    context->assets->AddTexture(CHASER, "assets/textures/chaserrr.png");
    chaser.Init(context->assets->GetTexture(CHASER)); //snake texture

    context->assets->AddTexture(s, "assets/textures/chaseddd.png");
    snek.setTexture(context->assets->GetTexture(s));
    snek.setPosition(context->window->getSize().x - 100, context->window->getSize().y - 100);


    context->assets->AddTexture(BORDER, "assets/textures/border.png.png", true);

    for(auto& wall : walls)
    {
        wall.setTexture(context->assets->GetTexture(BORDER));
    }
    walls[0].setTextureRect({0, 0, context->window->getSize().x, 16});
    walls[1].setTextureRect({0, 0, context->window->getSize().x, 16});
    walls[1].setPosition({0, context->window->getSize().y - 16});
    walls[2].setTextureRect({0, 0, 16, context->window->getSize().y});
    walls[3].setTextureRect({0, 0, 16, context->window->getSize().y});
    walls[3].setPosition({context->window->getSize().x - 16, 0});
}

void GamePlay::ProcessInput()
{
    sf::Event event;
    while (context->window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            context->window->close();
        }
        else if (event.type == sf::Event::KeyPressed)
        {
            
            
            sf::Vector2f newDirection = chaserDirection;

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                snek.move(-22.f, 0.f);


            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                snek.move(22.f, 0.f);      


            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                snek.move(0.f, -22.f);      


            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                snek.move(0.f, 22.f);
            }

            
            switch (event.key.code)
            {
            case sf::Keyboard::Up:
                newDirection = {0.f, -16.f};
                break;
            case sf::Keyboard::Down:
                newDirection = {0.f, 16.f};
                break;
            case sf::Keyboard::Left:
                newDirection = {-16.f, 0.f};
                break;
            case sf::Keyboard::Right:
                newDirection = {16.f, 0.f};
                break;

            default:
                break;
            }

        if (std::abs(chaserDirection.x) != std::abs(newDirection.x) ||
            std::abs(chaserDirection.y) != std::abs(newDirection.y))
        {
            chaserDirection = newDirection;
        }
    }
    }
}

void GamePlay::Update(sf::Time deltaTime)
{
    
    m_elapsedTime += deltaTime;
    if(m_elapsedTime.asSeconds() > 0.1)
    {
        bool isOnWall = false;
        chaser.Move(chaserDirection);
        m_elapsedTime = sf::Time::Zero;

        for (auto& wall : walls)
        {
            if(chaser.IsOn(wall))
            {
                context->states->Add(std::make_unique<gameover>(context), true);
                break;
            }

            if(chaser.IsOn(snek))
            {
                context->states->Add(std::make_unique<gameover>(context),true);
                break;
            }

            if(snek.getPosition().x > (975 -snek.getLocalBounds().width) || snek.getPosition().y >(800 - snek.getLocalBounds().height))
            {
                context->states->Add(std::make_unique<gameover>(context),true);
                break;
            }

            if(snek.getPosition().x <= 0 || snek.getPosition().y <= 0)
            {
                context->states->Add(std::make_unique<gameover>(context),true);
                break;
            }
            
        }


    }
}

void GamePlay::Draw()
{
    context->window->clear();
    context->window->draw(BACKGROUND);
    context->window->draw(chaser);
    for(auto& wall : walls)
    {
        context->window->draw(wall);
    }
    context->window->draw(snek);
    context->window->display();
   
}
