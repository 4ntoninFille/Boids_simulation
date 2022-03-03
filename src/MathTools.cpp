/*
** EPITECH PROJECT, 2022
** Boids_simulation
** File description:
** MathTools
*/

#include "MathTools.hpp"

MathTools::MathTools()
{
}

MathTools::~MathTools()
{
}

sf::Vector2f MathTools::normaliseVector(sf::Vector2f vector, int mag) const
{
    float div = sqrt(pow(vector.x, 2) + pow(vector.y, 2));

    vector.x = vector.x / div * mag;
    vector.y = vector.y / div * mag;

    return vector;
}

int MathTools::distance(sf::Vector2f p1, sf::Vector2f p2) const
{
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.x, 2));
}

sf::Vector2f MathTools::addVector(sf::Vector2f v1, sf::Vector2f v2) const
{
    v1.x += v2.x;
    v1.y += v2.y;

    return v1;
}