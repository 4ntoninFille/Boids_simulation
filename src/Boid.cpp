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
    spriteBoid = sf::Sprite();
    spriteBoid.setPosition(_position);
    _textureBoid = AssetManager<sf::Texture>::getAssetManager().getAsset("assets/boid.png");
    spriteBoid.setTexture(_textureBoid);
}

Boid::~Boid()
{
}

void Boid::draw()
{
    _window->draw(spriteBoid);
}