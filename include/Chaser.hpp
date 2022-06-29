#pragma once

#include <list>

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

class Chaser : public sf::Drawable
{
private:
    std::list<sf::Sprite> body;
    std::list<sf::Sprite>::iterator head;
    std::list<sf::Sprite>::iterator tail;

public:
    Chaser();
    ~Chaser();
    
    void Init(const sf::Texture &texture);
    void Move(const sf::Vector2f &direction);
    bool IsOn(const sf::Sprite &other) const;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};