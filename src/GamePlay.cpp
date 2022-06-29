#include "GamePlay.hpp"
#include "Snake.hpp"
#include <SFML/Window/Event.hpp>
#include "gameover.hpp"

GamePlay::GamePlay(std::shared_ptr<Context> &context)
    : context(context), m_snakeDirection({0.f, 0.f}), m_elapsedTime(sf::Time::Zero)
{

}

GamePlay::~GamePlay()
{

}
void GamePlay::Init()
{
    context->assets->AddTexture(background, "assets/textures/anyer.jpg");
    BACKGROUND.setTexture(context->assets->GetTexture(background));
    BACKGROUND.setTextureRect(context->window->getViewport(context->window->getDefaultView()));

    context->assets->AddTexture(SNAKE, "assets/textures/chaserrr.png");
    m_snake.Init(context->assets->GetTexture(SNAKE)); //snake texture

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
            
            
            sf::Vector2f newDirection = m_snakeDirection;
            // if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && snek.getPosition().x > 0)
            // {
            //     snek.move(-5.f, 0.f);


            // }
            // if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && snek.getPosition().x + snek.getLocalBounds().width < window.getSize().x)
            // {
            //     snek.move(5.f, 0.f);      


            // }
            // if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && snek.getPosition().y > 0)
            // {
            //     snek.move(0.f, -5.f);      


            // }
            // if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && snek.getPosition().y + snek.getLocalBounds().height < window.getSize().y)
            // {
            //     snek.move(0.f, 5.f);


            
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
            case sf::Keyboard::A:
                snek.move(-16.f, 0.f);
                break;
            case sf::Keyboard::D:
                snek.move(16.f, 0.f);
                break;
            case sf::Keyboard::W:
                snek.move(0.f, -16.f);
                break;
            case sf::Keyboard::S:
                snek.move(0.f, 16.f);
                break;
            // case sf::Keyboard::Escape:
            //     context->states->Add(std::make_unique<PauseGame>(m_context));
            //     break;

            default:
                break;
            }

            if (std::abs(m_snakeDirection.x) != std::abs(newDirection.x) ||
                std::abs(m_snakeDirection.y) != std::abs(newDirection.y))
            {
                m_snakeDirection = newDirection;
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
        bool iscollision = false;
        m_snake.Move(m_snakeDirection);
        m_elapsedTime = sf::Time::Zero;

        for (auto& wall : walls)
        {
            if(m_snake.IsOn(wall))
            {
                context->states->Add(std::make_unique<gameover>(context), true);
                break;
            }
        }

        if(m_snake.IsOn(snek))
        {
            context->states->Add(std::make_unique<gameover>(context),true);
            
        }
    }
    // snek.setPosition((sf::Mouse::getPosition(context->window).x), (sf::Mouse::getPosition(context->window).y));
   
}
void GamePlay::Draw()
{
    context->window->clear();
    context->window->draw(BACKGROUND);
    context->window->draw(m_snake);
    for(auto& wall : walls)
    {
        context->window->draw(wall);
    }
    context->window->draw(snek);
    context->window->display();
}
void GamePlay::Pause()
{

}
void GamePlay::Start()
{

}