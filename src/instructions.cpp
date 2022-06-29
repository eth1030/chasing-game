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
   // insprite in title
    // Title
    // inTitle.setFont(context->assets->GetFont(font));
    // inTitle.setString("Instructions");
    // inTitle.setOrigin(inTitle.getLocalBounds().width / 2,
    //                           inTitle.getLocalBounds().height / 2);
    // inTitle.setPosition(context->window->getSize().x / 2 - 100.f,
    //                             context->window->getSize().y / 2 - 150.f);
    // inTitle.setFillColor(sf::Color::Red);
    // inTitle.setCharacterSize(92);
    
    // image
    context->assets->AddTexture(sad, "assets/textures/finalinst.PNG");
    insprite.setTexture(context->assets->GetTexture(sad));
    // insprite.setScale(context->window->getSize().x/insprite.getLocalBounds().width, context->window->getSize().y/insprite.getLocalBounds().height);
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
    // context->window->draw(inTitle);
    context->window->display();
}