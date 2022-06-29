// #pragma once

// #include <list>

// #include <SFML/Graphics/Texture.hpp>
// #include <SFML/Graphics/Sprite.hpp>
// #include <SFML/Graphics/Drawable.hpp>
// #include <SFML/Graphics/RenderTarget.hpp>
// #include <SFML/Graphics/RenderStates.hpp>

// class Chased : public sf::Drawable
// {
// private:
//     std::list<sf::Sprite> chasedbody;
//     std::list<sf::Sprite>::iterator chasedhead;
//     std::list<sf::Sprite>::iterator chasedtail;

// public:
//     Chased();
//     ~Chased();

//     void cdInit(const sf::Texture &texture);
//     void cdMove(const sf::Vector2f &direction);
//     bool cdIsOn(const sf::Sprite &other) const;
//     void cddraw(sf::RenderTarget &target, sf::RenderStates states) const;
// };