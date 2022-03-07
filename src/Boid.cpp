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
    _maxSpeed = 10;
    _dir = normaliseVector({dx, dy});
    _dir = setMagnitudeVector(_dir, _maxSpeed);
    _boidSize = 5;

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

    sf::Vector2f vectorAlignement = {0, 0};
    sf::Vector2f vectorSeparation = {0, 0};
    sf::Vector2f vectorCohesion = {0, 0};

    sf::Vector2f finalVector = {0, 0};

    float dist = 0;

    for (auto it : boids) {
        dist = distance(this->_position, it->_position);
        if (dist < 100 && it != this) {
            //  alignement;
            vectorAlignement.x += it->_dir.x;
            vectorAlignement.y += it->_dir.y;

            //  cohesion
            vectorCohesion += it->_position;

            //  separation 
            vectorSeparation.x = _position.x - it->_position.x;
            vectorSeparation.y = _position.y - it->_position.y;

            vectorSeparation.x /= dist;
            vectorSeparation.y /= dist;

            //     alignement + separetion

            count += 1;
        }
    }
    if (count > 0) {
        //  alignement
        vectorAlignement.x /= count;
        vectorAlignement.y /= count;

        vectorAlignement = setMagnitudeVector(vectorAlignement, _maxSpeed);

        vectorAlignement.x -= _dir.x;
        vectorAlignement.y -= _dir.y;

        vectorAlignement = limitVector(vectorAlignement, _maxForce);

        //  cohesion

        vectorCohesion.x /= count;
        vectorCohesion.y /= count;

        vectorCohesion -= _position;

        vectorCohesion = setMagnitudeVector(vectorCohesion, _maxSpeed);

        vectorCohesion -= _dir;

        vectorCohesion = limitVector(vectorCohesion, _maxForce);

        //  separation

        vectorSeparation.x /= count;
        vectorSeparation.y /= count;

        vectorSeparation = setMagnitudeVector(vectorSeparation, _maxSpeed);

        vectorSeparation -= _dir;

        vectorSeparation = limitVector(vectorSeparation, _maxForce);

        finalVector +=  vectorAlignement + vectorCohesion + multVector(vectorSeparation, {1.2, 1.2});

    }
    _acceleration = finalVector;
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
