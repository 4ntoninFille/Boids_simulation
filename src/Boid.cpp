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
    _boidSize = 5;

    _coefAlignement = 1;
    _coefCohesion = 0.5;
    _coefSeparation = 1.2;

    _textureBoid = AssetManager<sf::Texture>::getAssetManager().getAsset("assets/ball.png");
    spriteBoid.setTexture(_textureBoid);
}

Boid::~Boid()
{
}

void Boid::update()
{
    align(_coreRef->getBoids());
    edge();

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
    int countSeparation = 0;

    sf::Vector2f vectorAlignement = {0, 0};
    sf::Vector2f vectorSeparation = {0, 0};
    sf::Vector2f vectorCohesion = {0, 0};

    sf::Vector2f finalVector = {0, 0};

    float dist = 0;

    for (auto it : boids) {
        dist = distance(this->_position, it->_position);
        if (dist < 50) {
            //  alignement;
            vectorAlignement.x += it->_dir.x;
            vectorAlignement.y += it->_dir.y;

            //  cohesion
            vectorCohesion += it->_position;

            //  separation 
            if (it != this && dist < 30) {
                vectorSeparation.x = _position.x - it->_position.x;
                vectorSeparation.y = _position.y - it->_position.y;
                countSeparation += 1;
            }

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

        if (countSeparation > 0) {
            vectorSeparation.x /= count;
            vectorSeparation.y /= count;

            vectorSeparation = setMagnitudeVector(vectorSeparation, _maxSpeed);

            vectorSeparation -= _dir;

            vectorSeparation = limitVector(vectorSeparation, _maxForce);
        }

        finalVector += multVector(vectorAlignement, {_coefAlignement, _coefAlignement})
                        + multVector(vectorCohesion, {_coefCohesion, _coefCohesion})
                        + multVector(vectorSeparation, {_coefSeparation, _coefSeparation});

    }
    _acceleration = finalVector;
}

void Boid::edge()
{
    if (_position.x > WIN_WIDTH - 40) {
        _acceleration.x -= 0.5;
    } else if (_position.x < 40) {
        _acceleration.x += 0.5;
    }

    if (_position.y > WIN_HEIGHT - 40) {
        _acceleration.y -= 0.5;
    } else if (_position.y < 40) {
        _acceleration.y += 0.5;
    }

    _acceleration = limitVector(_acceleration, _maxSpeed);
}

void Boid::addCoefAlignement(float value)
{
    _coefAlignement += value;
}

void Boid::addCoefCohesion(float value)
{
    _coefCohesion += value;
}
void Boid::addCoefSeparation(float value)
{
    _coefSeparation += value;
}

float Boid::getPositionX() const
{
    return _position.x;
}

float Boid::getPositionY() const
{
    return _position.y;
}