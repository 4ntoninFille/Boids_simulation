/*
** EPITECH PROJECT, 2022
** Boids_simulation
** File description:
** QTree
*/

#ifndef QTREE_HPP_
#define QTREE_HPP_

#define MAXBOID 5

#include "Boundary.hpp"
#include "Boid.hpp"

class Boid;

class QTree {
public:
    QTree(Boundary boundry);
    ~QTree();

    void insertBoid(Boid *newBoid);

    QTree *northWest;
    QTree *northEst;
    QTree *southWest;
    QTree *southEst;

    Boundary            boundary;
    std::vector<Boid *> Boids;

protected:
private:
    void _division();

    bool _divided;
};

#endif /* !QTREE_HPP_ */