/*
** EPITECH PROJECT, 2022
** Boids_simulation
** File description:
** Boundary
*/

#ifndef BOUNDARY_HPP_
#define BOUNDARY_HPP_

class Boundary {
public:
    Boundary(float x, float y, float width, float height);
    ~Boundary();

    bool    contains(float x, float y);

    float _x;
    float _y;
    float _width;
    float _height;
protected:
private:
};

#endif /* !BOUNDaRY_HPP_ */