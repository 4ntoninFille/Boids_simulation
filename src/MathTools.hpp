/*
** EPITECH PROJECT, 2022
** Boids_simulation
** File description:
** MathTools
*/

#ifndef MATHTOOLS_HPP_
#define MATHTOOLS_HPP_

#include <SFML/Graphics.hpp>

#include <math.h>

class MathTools {
public:
    MathTools();
    ~MathTools();

    sf::Vector2f    normaliseVector(sf::Vector2f vec) const;
    sf::Vector2f    setMagnitudeVector(sf::Vector2f vec, float mag) const;
    sf::Vector2f    limitVector(sf::Vector2f vec, float maxForce) const;
    float           distance(sf::Vector2f p1, sf::Vector2f p2) const;
    sf::Vector2f    addVector(sf::Vector2f v1, sf::Vector2f v2) const;

protected:
private:
};

#endif /* !MATHTOOLS_HPP_ */