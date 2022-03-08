/*
** EPITECH PROJECT, 2022
** Boids_simulation
** File description:
** QTree
*/

#include "QTree.hpp"

QTree::QTree(Boundary bndry)
    :   boundary(bndry)
{
    _divided = false;
}

QTree::~QTree()
{
    if (_divided) {
        northEst->~QTree();
        northWest->~QTree();
        southEst->~QTree();
        southWest->~QTree();
    }

    delete northEst;
    delete northWest;
    delete southEst;
    delete southWest;
}

void QTree::insertBoid(Boid *newBoid)
{
    if (!boundary.contains(newBoid->getPositionX(), newBoid->getPositionY())) {
        return;
    }

    if (Boids.size() <= MAXBOID) {
        Boids.push_back(newBoid);
        return;
    }
    
    if (!_divided) {
        _division();
    }

    northEst->insertBoid(newBoid);
    northWest->insertBoid(newBoid);
    southEst->insertBoid(newBoid);
    southWest->insertBoid(newBoid);
}

void QTree::_division()
{
    northEst = new QTree(Boundary(boundary._x + boundary._width / 4,
                                    boundary._y - boundary._height / 4,
                                    boundary._width / 2,
                                    boundary._height / 2));

    northWest = new QTree(Boundary(boundary._x - boundary._width / 4,
                                    boundary._y - boundary._height / 4,
                                    boundary._width / 2,
                                    boundary._height / 2));
    
    southEst = new QTree(Boundary(boundary._x + boundary._width / 4,
                                    boundary._y + boundary._height / 4,
                                    boundary._width / 2,
                                    boundary._height / 2));
    
    southWest = new QTree(Boundary(boundary._x - boundary._width / 4,
                                    boundary._y + boundary._height / 4,
                                    boundary._width / 2,
                                    boundary._height / 2));

    _divided = true;
}