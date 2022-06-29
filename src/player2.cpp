#include "player2.hpp"
#include <iostream> 
#include <SFML/Graphics.hpp>
#include <cmath>

Player::Player(sf::Vector2f position) 
{
    playerSize = 5;

    pDot.setFillColor(sf::Color::Green);
    pDot.setPosition(position);
    pDot.setRadius(playerSize);
    pDot.setOrigin(pDot.getLocalBounds().width/2, pDot.getLocalBounds().height/2);
    life = true;
}


void Player::draw(sf::RenderWindow &window)
{
    if (life)
    {
        window.draw(pDot);
    }
}

bool Player::collision(sf::CircleShape& circle)
{
    sf::CircleShape& player = pDot;
    sf::CircleShape& enemy = circle;
    enemy.setOrigin(enemy.getLocalBounds().width/2, enemy.getLocalBounds().height/2);

    // distance between player and enemy
    float xDist = player.getPosition().x - enemy.getPosition().x;
    float yDist = player.getPosition().y - enemy.getPosition().y;
    float dist = sqrt(xDist*xDist + yDist*yDist);

    if (dist < player.getRadius() + enemy.getRadius())
    {
        getBigger();
        return true;
    }
    return false;
}

void Player:: getBigger()
{
    playerSize+= 2; 
    pDot.setRadius(playerSize);
    pDot.setOrigin(pDot.getLocalBounds().width/2, pDot.getLocalBounds().height/2);
}


Player::~Player() {

}