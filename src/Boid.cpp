/*
** EPITECH PROJECT, 2022
** Boids_simulation
** File description:
** Boid
*/

#include "Boid.hpp"

Boid::Boid(Core &coreRef, float x, float y)
    :   _coreRef(&coreRef), _position(sf::Vector2f(x, y))
{
    float dx = (rand() % 10 + 1) - 5;
    float dy = (rand() % 10 + 1) - 5;

    spriteBoid = sf::Sprite();
    spriteBoid.setPosition(_position);

    _dir = normaliseVector({dx, dy});

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
    _coreRef->getWindow()->draw(spriteBoid);
}