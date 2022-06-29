#include "Chaser.hpp"

Chaser::Chaser() : body(std::list<sf::Sprite>(1))
{
    head = --body.end();
    tail = body.begin();
}

Chaser::~Chaser()
{
}

void Chaser::Init(const sf::Texture &texture)
{
    float x = 16.f;
    for (auto &piece : body)
    {
        piece.setTexture(texture);
        piece.setPosition({100.f, 100.f});
        x += 16.f;
    }
}

void Chaser::Move(const sf::Vector2f &direction)
{
    tail->setPosition(head->getPosition() + direction);
    head = tail;
    ++tail;

    if (tail == body.end())
    {
        tail = body.begin();
    }
}

bool Chaser::IsOn(const sf::Sprite &other) const
{
    return other.getGlobalBounds().intersects(head->getGlobalBounds());
}


void Chaser::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    for (auto &piece : body)
    {
        target.draw(piece);
    }
}

