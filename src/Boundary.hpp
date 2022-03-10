/*
** EPITECH PROJECT, 2022
** Boids_simulation
** File description:
** Boundary
*/

#ifndef BOUNDARY_HPP_
#define BOUNDARY_HPP_

#include <SFML/Graphics.hpp>

class Boundary {
public:
    Boundary(float x, float y, float width, float height);
    ~Boundary();

    bool    contains(float x, float y) const;
    bool    intersect(Boundary range) const;

    float _x;
    float _y;
    float _width;
    float _height;

    float _left; 
    float _right;
    float _top;
    float _bottom;

    sf::RectangleShape shaped;
protected:
private:
};

#endif /* !BOUNDaRY_HPP_ */