/*
** EPITECH PROJECT, 2022
** Boids_simulation
** File description:
** QTree
*/

#include "QTree.hpp"

QTree::QTree(Boundary bndry, sf::RenderWindow *win)
    :   boundary(bndry)
{
    _divided = false;
    _win = win;
}

QTree::~QTree()
{
    if (_divided) {
        northEst->~QTree();
        northWest->~QTree();
        southEst->~QTree();
        southWest->~QTree();
    } else {
        return;
    }
}

void QTree::insertBoid(Boid *newBoid)
{
    if (!boundary.contains(newBoid->getPositionX(), newBoid->getPositionY())) {
        return;
    }

    if (boids.size() <= MAXBOID) {
        boids.push_back(newBoid);
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
                                    boundary._height / 2),
                                    _win);

    northWest = new QTree(Boundary(boundary._x - boundary._width / 4,
                                    boundary._y - boundary._height / 4,
                                    boundary._width / 2,
                                    boundary._height / 2),
                                    _win);
    
    southEst = new QTree(Boundary(boundary._x + boundary._width / 4,
                                    boundary._y + boundary._height / 4,
                                    boundary._width / 2,
                                    boundary._height / 2),
                                    _win);
    
    southWest = new QTree(Boundary(boundary._x - boundary._width / 4,
                                    boundary._y + boundary._height / 4,
                                    boundary._width / 2,
                                    boundary._height / 2),
                                    _win);

    _divided = true;
}

void QTree::cleanTree()
{
    if (_divided) {
        // northEst->cleanTree();
        // northWest->cleanTree();
        // southEst->cleanTree();
        // southWest->cleanTree();

        boids.clear();
        
        delete northEst;
        delete northWest;
        delete southEst;
        delete southWest;
        _divided = false;
    } else {
        return;
    }
}

void QTree::showBoundary() const
{
    if (_divided) {
        northEst->showBoundary();
        northWest->showBoundary();
        southEst->showBoundary();
        southWest->showBoundary();
    }

    sf::RectangleShape rec({boundary._width, boundary._height});
    rec.setOrigin({boundary._width / 2, boundary._height / 2});
    rec.setFillColor({0, 0, 0, 0});
    rec.setOutlineThickness(1);
    rec.setOutlineColor({255, 255, 255, 255});

    rec.setPosition({boundary._x, boundary._y});

    _win->draw(rec);
}