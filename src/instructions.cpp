#include "instructions.hpp"
#include "mainmenu.hpp"


#include <SFML/Window/Event.hpp>

instructions::instructions(std::shared_ptr<Context> &context)
    : context(context), enterpressed(false)
{
}

instructions::~instructions()
{
}

void instructions::Init()
{
    // image
    context->assets->AddTexture(sad, "assets/textures/finalinst.PNG");
    insprite.setTexture(context->assets->GetTexture(sad));
    insprite.setOrigin(insprite.getLocalBounds().width/2,insprite.getLocalBounds().height/2);
    insprite.setPosition(context->window->getSize().x/2, context->window->getSize().y/2);
}

void instructions::ProcessInput()
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
                case sf::Keyboard::Enter:
                {
                    if (!enterpressed)
                    {
                        enterpressed = true;
                    }
                    break;
                }
            
            }
        }
    }
}

void instructions::Update(sf::Time deltaTime)
{
    if (enterpressed)
    {
        context->states->Add(std::make_unique<mainmenu>(context), true);
    }
}

void instructions::Draw()
{
    context->window->clear(sf::Color::Red);
    context->window->draw(insprite);
    context->window->display();
}