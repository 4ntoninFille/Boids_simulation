/*
** EPITECH PROJECT, 2022
** Boids_simulation
** File description:
** Boid
*/

#include "Boid.hpp"

Boid::Boid(Core &coreRef, float x, float y, int id)
    :   _coreRef(&coreRef), _position(sf::Vector2f(x, y)), _id(id)
{
    float dx = 0;
    float dy = 0;

    while (dx == 0 && dy == 0) {
        dx = (rand() % 10) - 5;
        dy = (rand() % 10) - 5;
    }


    spriteBoid = sf::Sprite();
    spriteBoid.setOrigin({10, 10});
    spriteBoid.setPosition(_position);

    _maxForce = 0.1;
    _maxSpeed = 5;
    _dir = normaliseVector({dx, dy});
    _dir = setMagnitudeVector(_dir, _maxSpeed);
    _boidSize = 10;

    // std::cout << "position:(" << _position.x << ";" << _position.y << ") v=" 
    //     << _dir.x << ", " << _dir.y << " | "
    //     << dx << ", " << dy << std::endl;

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

    float avgx = 0;
    float avgy = 0;
    sf::Vector2f dif = {0, 0};
    float dist = 0;

    for (auto it : boids) {
        dist = distance(this->_position, it->_position);
        // std::cout << "id[" << _id << "]" << distance(this->_position, it->_position)
        // << "\t\t" << _position.x << ";" << _position.y
        // << " | " << it->_position.x << ";" << it->_position.y << std::endl;
        if (dist < 200 && it != this) {
            desired.x += it->_dir.x;
            desired.y += it->_dir.y;

            dif.x = _position.x - it->_position.x;
            dif.y = _position.y - it->_position.y;

            dif.x /= dist;
            dif.y /= dist;

            //     alignement + cohsion + separetion
            avgx += it->_dir.x + dif.x;
            avgy += it->_dir.y + dif.y;

            count += 1;
        }
    }
    if (count > 0) {
        desired.x = avgx / count;
        desired.y = avgy / count;

        desired = setMagnitudeVector(desired, _maxSpeed);

        desired.x -= _dir.x;
        desired.y -= _dir.y;

        desired = limitVector(desired, _maxForce);
    }
    _acceleration = desired;
}

void Boid::edge()
{
    if (_position.x > WIN_WIDTH + _boidSize) {
        _position.x = -_boidSize;
    } else if (_position.x < -_boidSize) {
        _position.x = WIN_WIDTH - _boidSize;
    }
    if (_position.y > WIN_HEIGHT + _boidSize) {
        _position.y = -_boidSize;
    } else if (_position.y < 0 - _boidSize) {
        _position.y = WIN_HEIGHT - _boidSize;
    }
}
