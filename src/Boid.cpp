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

    _dir = normaliseVector({dx, dy}, 5);

    // _textureBoid = AssetManager<sf::Texture>::getAssetManager().getAsset("assets/boid.png");
    _textureBoid = AssetManager<sf::Texture>::getAssetManager().getAsset("assets/ball.png");

    spriteBoid.setTexture(_textureBoid);
}

Boid::~Boid()
{
}

void Boid::update()
{
    edge();
    align(_coreRef->getBoids());

    _position = addVector(_dir, _position);
    _dir = addVector(_dir, _acceleration);

    spriteBoid.setPosition(_position);

}

void Boid::draw()
{
    _coreRef->getWindow()->draw(spriteBoid);
}

void Boid::align(std::vector<Boid *> boids)
{
    int count = 0;
    sf::Vector2f desired = {0, 0};
    for (auto it : boids) {
        if (distance(this->_position, it->_position) < 100 && it != this) {
            desired.x += it->_dir.x;
            desired.y += it->_dir.y;
            count += 1;
        }
    }
    if (count > 0) {
        desired.x /= count;
        desired.y /= count;

        desired.x -= _dir.x;
        desired.y -= _dir.y;
    }
    _acceleration = desired;
}

void Boid::edge()
{
    if (_position.x > WIN_WIDTH + 10) {
        _position.x = -10;
    } else if (_position.x < -10) {
        _position.x = WIN_WIDTH - 10;
    }
    if (_position.y > WIN_HEIGHT + 10) {
        _position.y = -10;
    } else if (_position.y < 0 - 10) {
        _position.y = WIN_HEIGHT - 10;
    }
}