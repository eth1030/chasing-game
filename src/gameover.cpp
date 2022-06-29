#include "gameover.hpp"
#include "GamePlay.hpp"

#include <SFML/Window/Event.hpp>

gameover::gameover(std::shared_ptr<Context> &context)
    : context(context), m_isRetryButtonSelected(true),
      m_isRetryButtonPressed(false), m_isExitButtonSelected(false),
      m_isExitButtonPressed(false)
{
}

gameover::~gameover()
{
}

void gameover::Init()
{
    // Title
    m_gameOverTitle.setFont(context->assets->GetFont(font));
    m_gameOverTitle.setString("Game Over");
    m_gameOverTitle.setOrigin(m_gameOverTitle.getLocalBounds().width / 2,
                              m_gameOverTitle.getLocalBounds().height / 2);
    m_gameOverTitle.setPosition(context->window->getSize().x / 2,
                                context->window->getSize().y / 2 - 150.f);

    // Play Button
    m_retryButton.setFont(context->assets->GetFont(font));
    m_retryButton.setString("Retry");
    m_retryButton.setOrigin(m_retryButton.getLocalBounds().width / 2,
                            m_retryButton.getLocalBounds().height / 2);
    m_retryButton.setPosition(context->window->getSize().x / 2,
                              context->window->getSize().y / 2 - 25.f);
    m_retryButton.setCharacterSize(20);

    // Exit Button
    m_exitButton.setFont(context->assets->GetFont(font));
    m_exitButton.setString("Exit");
    m_exitButton.setOrigin(m_exitButton.getLocalBounds().width / 2,
                           m_exitButton.getLocalBounds().height / 2);
    m_exitButton.setPosition(context->window->getSize().x / 2,
                             context->window->getSize().y / 2 + 25.f);
    m_exitButton.setCharacterSize(20);
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
                if (!m_isRetryButtonSelected)
                {
                    m_isRetryButtonSelected = true;
                    m_isExitButtonSelected = false;
                }
                break;
            }
            case sf::Keyboard::Down:
            {
                if (!m_isExitButtonSelected)
                {
                    m_isRetryButtonSelected = false;
                    m_isExitButtonSelected = true;
                }
                break;
            }
            case sf::Keyboard::Return:
            {
                m_isRetryButtonPressed = false;
                m_isExitButtonPressed = false;

                if (m_isRetryButtonSelected)
                {
                    m_isRetryButtonPressed = true;
                }
                else
                {
                    m_isExitButtonPressed = true;
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
    if (m_isRetryButtonSelected)
    {
        m_retryButton.setFillColor(sf::Color::Yellow);
        m_exitButton.setFillColor(sf::Color::White);
    }
    else
    {
        m_exitButton.setFillColor(sf::Color::Yellow);
        m_retryButton.setFillColor(sf::Color::White);
    }

    if (m_isRetryButtonPressed)
    {
        context->states->Add(std::make_unique<GamePlay>(context), true);
    }
    else if (m_isExitButtonPressed)
    {
        context->window->close();
    }
}

void gameover::Draw()
{
    context->window->clear(sf::Color::Blue);
    context->window->draw(m_gameOverTitle);
    context->window->draw(m_retryButton);
    context->window->draw(m_exitButton);
    context->window->display();
}