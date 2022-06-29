// #include "Chased.hpp"

// Chased::Chased() : chasedbody(std::list<sf::Sprite>(1))
// {
//     chasedhead = --chasedbody.end();
//     chasedtail = chasedbody.begin();
// }

// Chased::~Chased()
// {
// }

// void Chased::cdInit(const sf::Texture &texture)
// {
//     float x = 16.f;
//     for (auto &piece : chasedbody)
//     {
//         piece.setTexture(texture);
//         piece.setPosition({500.f, 500.f});
//         x += 16.f;
//     }
// }

// void Chased::cdMove(const sf::Vector2f &direction)
// {
//     chasedtail->setPosition(chasedhead->getPosition() + direction);
//     chasedhead = chasedtail;
//     ++chasedtail;

//     if (chasedtail == chasedbody.end())
//     {
//         chasedtail = chasedbody.begin();
//     }
// }

// bool Chased::cdIsOn(const sf::Sprite &other) const
// {
//     return other.getGlobalBounds().intersects(chasedhead->getGlobalBounds());
// }


// void Chased::cddraw(sf::RenderTarget &target, sf::RenderStates states) const
// {
//     for (auto &piece : chasedbody)
//     {
//         target.draw(piece);
//     }
// }