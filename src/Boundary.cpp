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

bool Boundary::intersect(float ptx, float pty, float width, float height) const
{
    
    return !(ptx - width > _x + _width
            || ptx + width < _x - _width
            || pty - height > _y + _height
            || pty + height < _y - _height);
}