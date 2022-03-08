/*
** EPITECH PROJECT, 2022
** Boids_simulation
** File description:
** Boundary
*/

#include "Boundary.hpp"

Boundary::Boundary(float x, float y, float width, float height)
    :   _x(x),
        _y(y),
        _width(width),
        _height(height)
{
}

Boundary::~Boundary()
{
}

bool Boundary::contains(float ptx, float pty)
{
    if (ptx >= _x - _width / 2 && ptx <= _x + _width / 2) {
        if (pty >= _y - _width / 2 && pty <= _y + _height / 2) {
            return true;
        }
    }
    return false;
}