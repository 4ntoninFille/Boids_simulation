/*
** EPITECH PROJECT, 2022
** Boids_simulation
** File description:
** Boundary
*/

#include "Boundary.hpp"
#include <SFML/Graphics.hpp>

#include <iostream>

Boundary::Boundary(float x, float y, float width, float height)
    :   _x(x),
        _y(y),
        _width(width),
        _height(height)
{
    _left = x - width / 2;
    _right = x + width / 2;
    _top = y - height / 2;
    _bottom = y + height / 2;
    shaped = sf::RectangleShape({width, height});
    shaped.setOrigin({width / 2, height / 2});
    shaped.setFillColor({0, 0, 0, 0});
    shaped.setOutlineThickness(1);
    shaped.setOutlineColor({255, 255, 255, 255});

    shaped.setPosition({_x, _y});
}

Boundary::~Boundary()
{
}

bool Boundary::contains(float ptx, float pty) const
{
    if (ptx >= _x - _width / 2 && ptx <= _x + _width / 2) {
        if (pty >= _y - _width / 2 && pty <= _y + _height / 2) {
            return true;
        }
    }
    return false;
}

bool Boundary::intersect(Boundary range) const
{
    
    return !(
        this->_right < range._left || range._right < this->_left ||
        this->_bottom < range._top || range._bottom < this->_top
    );
}