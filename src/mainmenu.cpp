#include "mainmenu.hpp"
// #include <iostream>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Mouse.hpp>
#include "GamePlay.hpp"
#include "instructions.hpp"

mainmenu::mainmenu(std::shared_ptr<Context> &context) 
    : context(context), isPlay(false), isExit(false),
     isPlaySelected(true), isExitSelected(false),
     isInstructions(false), isInstructionsSelected(false)
{
    

}

mainmenu::~mainmenu()
{
}

void mainmenu::Init() 
{
    // adding the font
    context->assets->AddFont(font, "assets/fonts/Anton-Regular.ttf"); 
    // add image
    context->assets->AddTexture(my, "assets/textures/mainmenu.JPG");
    sprite.setTexture(context->assets->GetTexture(my));
    sprite.setScale(context->window->getSize().x/sprite.getLocalBounds().width, context->window->getSize().y/sprite.getLocalBounds().height);
    sprite.setOrigin(sprite.getLocalBounds().width/2,sprite.getLocalBounds().height/2);
    sprite.setPosition(context->window->getSize().x/2, context->window->getSize().y/2);
    
    // initializing title text
    title.setFont(context->assets->GetFont(font));
    title.setString("Predator & Prey");
    title.setFillColor(sf::Color::Red);
    title.setPosition(context->window->getSize().x/2,
                      context->window->getSize().y/2 - 150.f);
    title.setOrigin(title.getLocalBounds().width/.67,title.getLocalBounds().height/2);
    title.setCharacterSize(92);
    // play button 
    play.setFont(context->assets->GetFont(font));
    play.setString("Play");
    play.setPosition(context->window->getSize().x/2.1,
                      context->window->getSize().y/2 - 25.f);
    play.setOrigin(play.getLocalBounds().width/2,play.getLocalBounds().height/2);
    play.setCharacterSize(50);
    // exit button
    exit.setFont(context->assets->GetFont(font));
    exit.setString("Exit");
    exit.setPosition(context->window->getSize().x/2.075,
                      context->window->getSize().y/2 + 100.f);
    exit.setOrigin(exit.getLocalBounds().width/2,exit.getLocalBounds().height/2);
    exit.setCharacterSize(45);
    // instructions
    instructionsa.setFont(context->assets->GetFont(font));
    instructionsa.setString("Instructions");
    instructionsa.setPosition(context->window->getSize().x/2.22,
                      context->window->getSize().y/2 + 35);
    instructionsa.setOrigin(instructionsa.getLocalBounds().width/2, instructionsa.getLocalBounds().height/2);
    instructionsa.setCharacterSize(50);
    
}

void mainmenu::ProcessInput()
{
    sf::Event event;
    while (context->window->pollEvent(event)) 
    {
        if (event.type == sf::Event::Closed)
            context->window->close();
        else if (event.type == sf::Event::KeyPressed)
        {
            switch (event.key.code)
            {
                case sf::Keyboard::Up:
                {
                    if (!isExitSelected && !isPlaySelected)
                    {
                        isPlaySelected = true;
                        isExitSelected = false;
                        isInstructionsSelected = false;
                    }
                    else if (!isPlaySelected && !isInstructionsSelected)
                    {
                        isPlaySelected = false;
                        isExitSelected = false;
                        isInstructionsSelected = true;
                    }
                     break;
                }

                case sf::Keyboard::Down:
                {
                    if (!isExitSelected && !isInstructionsSelected)
                    {
                        isPlaySelected = false;
                        isExitSelected = false;
                        isInstructionsSelected = true;
                    }
                    else if (!isExitSelected && !isPlaySelected)
                    {
                        isPlaySelected = false;
                        isExitSelected = true;
                        isInstructionsSelected = false;
                    }
                     break;
                }
                case sf::Keyboard::Enter:
                {
                    isPlay = false;
                    isExit = false;
                    isInstructions = false;
                    if (isPlaySelected) 
                    {
                        isExit = true;
                    }
                    else if (isExitSelected)
                    {
                        isPlay = true;
                    }
                    else if (isInstructionsSelected)
                    {
                        isInstructions = true;
                    }
                    break;
                }
                default:
                    break;



            }
        }
    
    }
}
void mainmenu::Update(sf::Time deltaTime)
{
    if(isPlaySelected) 
    {
        play.setFillColor(sf::Color::Red);
        exit.setFillColor(sf::Color::Black);
        instructionsa.setFillColor(sf::Color::Black);
    }
    else if(isExitSelected)
    {
        exit.setFillColor(sf::Color::Red);
        play.setFillColor(sf::Color::Black);
        instructionsa.setFillColor(sf::Color::Black);
    }   
    else
    {
        exit.setFillColor(sf::Color::Black);
        play.setFillColor(sf::Color::Black);
        instructionsa.setFillColor(sf::Color::Red);
    }

    if(isExit) { // actually is if play is selected
        context->states->Add(std::make_unique<GamePlay>(context), true);
    }
    else if (isPlay) // actually is if exit is selected...
    {
        context->window->close();
    }
    else if (isInstructions)
    {
        context->states->Add(std::make_unique<instructions>(context), true);
    }
    
}
void mainmenu::Draw()
{
    context->window->clear(sf::Color::Red);
    context->window->draw(sprite);
    context->window->draw(title);
    context->window->draw(play);
    context->window->draw(exit);
    context->window->draw(instructionsa);
    context->window->display();
}