#include "gameover.hpp"
#include "GamePlay.hpp"

#include <SFML/Window/Event.hpp>

gameover::gameover(std::shared_ptr<Context> &context)
    : context(context), endretrySelected(true),
      endretryPressed(false), endexitSelected(false),
      endexitPressed(false)
{
}

gameover::~gameover()
{
}

void gameover::Init()
{
    // Title
    endTitle.setFont(context->assets->GetFont(font));
    endTitle.setString("Game Over");
    endTitle.setOrigin(endTitle.getLocalBounds().width / 2,
                              endTitle.getLocalBounds().height / 2);
    endTitle.setPosition(context->window->getSize().x / 2 - 100.f,
                                context->window->getSize().y / 2 - 150.f);
    endTitle.setFillColor(sf::Color::Red);
    endTitle.setCharacterSize(92);
    // Play Button
    endretry.setFont(context->assets->GetFont(font));
    endretry.setString("Replay");
    endretry.setOrigin(endretry.getLocalBounds().width / 2,
                            endretry.getLocalBounds().height / 2);
    endretry.setPosition(context->window->getSize().x / 2,
                              context->window->getSize().y / 2 - 25.f);
    endretry.setCharacterSize(50);

    // Exit Button
    endexit.setFont(context->assets->GetFont(font));
   endexit.setString("Exit");
    endexit.setOrigin(endexit.getLocalBounds().width / 2,
                           endexit.getLocalBounds().height / 2);
    endexit.setPosition(context->window->getSize().x / 2,
                             context->window->getSize().y / 2 + 50.f);
    endexit.setCharacterSize(50);

    // image
    context->assets->AddTexture(sad, "assets/textures/end.PNG");
    endsprite.setTexture(context->assets->GetTexture(sad));
    endsprite.setScale(context->window->getSize().x/endsprite.getLocalBounds().width, context->window->getSize().y/endsprite.getLocalBounds().height);
    endsprite.setOrigin(endsprite.getLocalBounds().width/2,endsprite.getLocalBounds().height/2);
    endsprite.setPosition(context->window->getSize().x/2, context->window->getSize().y/2);
}

void gameover::ProcessInput()
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
            switch (event.key.code)
            {
            case sf::Keyboard::Up:
            {
                if (!endretrySelected)
                {
                    endretrySelected = true;
                    endexitSelected = false;
                }
                break;
            }
            case sf::Keyboard::Down:
            {
                if (!endexitSelected)
                {
                    endretrySelected = false;
                    endexitSelected = true;
                }
                break;
            }
            case sf::Keyboard::Enter:
            {
                endexitPressed = false;
                endexitPressed = false;

                if (endretrySelected)
                {
                    endretryPressed = true;
                }
                else
                {
                    endexitPressed = true;
                }

                break;
            }
            default:
            {
                break;
            }
            }
        }
    }
}

void gameover::Update(sf::Time deltaTime)
{
    if (endretrySelected)
    {
        endretry.setFillColor(sf::Color::Red);
        endexit.setFillColor(sf::Color::Black);
    }
    else
    {
        endexit.setFillColor(sf::Color::Red);
        endretry.setFillColor(sf::Color::Black);
    }

    if (endretryPressed)
    {
        context->states->Add(std::make_unique<GamePlay>(context), true);
    }
    else if (endexitPressed)
    {
        context->window->close();
    }
}

void gameover::Draw()
{
    context->window->clear(sf::Color::Red);
    context->window->draw(endsprite);
    context->window->draw(endTitle);
    context->window->draw(endretry);
    context->window->draw(endexit);
    context->window->display();
}
