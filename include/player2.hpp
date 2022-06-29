#pragma once

#include <SFML/Graphics.hpp>
class Player {
private:
    int playerSize;
    sf::CircleShape pDot;
public:
    Player(sf::Vector2f position);
    ~Player();

    void move(sf::Vector2f &direction);
    void draw(sf::RenderWindow &window);
    bool collision(sf::CircleShape &dot);
    bool life;
    void getBigger();
    void setPlayerSize(int newSize);
};