/*
** EPITECH PROJECT, 2022
** Boids_simulation
** File description:
** MathTools
*/

#include "MathTools.hpp"
#include <iostream>
#include <unistd.h>

MathTools::MathTools()
{
}

MathTools::~MathTools()
{
}

sf::Vector2f MathTools::normaliseVector(sf::Vector2f vector) const
{
    if (vector.x == 0 && vector.y == 0) {
        std::cout << "SHIIIIT" << std::endl;
    }
    float div = sqrt(pow(vector.x, 2) + pow(vector.y, 2));

    vector.x = vector.x / div;
    vector.y = vector.y / div;

    // std::cout << vector.x << ";" << vector.y << std::endl;
    // usleep(1000);
    return vector;
}

sf::Vector2f MathTools::multVector(sf::Vector2f v1, sf::Vector2f v2) const
{
    return {(v1.x * v2.x), (v1.y * v2.y)};
}

float MathTools::distance(sf::Vector2f p1, sf::Vector2f p2) const
{
    float dist  = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    return dist;
}

sf::Vector2f MathTools::addVector(sf::Vector2f v1, sf::Vector2f v2) const
{
    v1.x += v2.x;
    v1.y += v2.y;

    return v1;
}

sf::Vector2f MathTools::limitVector(sf::Vector2f vec, float maxforce) const
{
    float mag = sqrt(pow(vec.x, 2) + pow(vec.y, 2));
    if (mag > maxforce ) {
        vec = setMagnitudeVector(vec, maxforce);
    }
    return vec;
}

sf::Vector2f MathTools::setMagnitudeVector(sf::Vector2f vec, float newMag) const
{
    if (vec.x == 0 && vec.y == 0) {
        return vec;
    }
    float mag = sqrt(pow(vec.x, 2) + pow(vec.y, 2));
    vec.x = vec.x * newMag / mag;
    vec.y = vec.y * newMag / mag;

    // std::cout << sqrt(pow(vec.x, 2) + pow(vec.y, 2)) << std::endl;

    // usleep(1000);

    return vec;
}
