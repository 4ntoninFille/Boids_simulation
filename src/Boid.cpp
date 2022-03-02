/*
** EPITECH PROJECT, 2022
** Boids_simulation
** File description:
** Boid
*/

#include "Boid.hpp"

Boid::Boid(sf::RenderWindow *window, float x, float y)
    :   _window(window), _position(sf::Vector2f(x, y))
{
    float dx = (rand() % 10 + 1) - 5;
    float dy = (rand() % 10 + 1) - 5;

    float div = sqrt(pow(x, 2) + pow(y, 2));
 
    _dir.x = (dx / div) * 100;
    _dir.y = (dy / div) * 100;

    std::cout << _dir.x << std::endl;

    spriteBoid = sf::Sprite();
    spriteBoid.setPosition(_position);
    // _textureBoid = AssetManager<sf::Texture>::getAssetManager().getAsset("assets/boid.png");
    _textureBoid = AssetManager<sf::Texture>::getAssetManager().getAsset("assets/ball.png");

    spriteBoid.setTexture(_textureBoid);
}

Boid::~Boid()
{
}

void Boid::update()
{
    spriteBoid.move(_dir);
}

void Boid::draw()
{
    _window->draw(spriteBoid);
}