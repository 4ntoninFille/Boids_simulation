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

bool QTree::insertBoid(Boid *newBoid)
{
    if (!boundary.contains(newBoid->getPositionX(), newBoid->getPositionY())) {
        return false;
    }

    if ((boids.size() < MAXBOID && !_divided) || (boundary._width <= 20 && boundary._height <= 20)) {
        boids.push_back(newBoid);
        return true;
    }

    if (!_divided) {
        _division();
    }

    return (northEst->insertBoid(newBoid) ||
            northWest->insertBoid(newBoid) ||
            southEst->insertBoid(newBoid) ||
            southWest->insertBoid(newBoid));
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

    for (auto it : boids) {
        boids.clear();

        if (northEst->insertBoid(it)) {
            continue;
        }
        if (northWest->insertBoid(it)) {
            continue;
        }
        if (southEst->insertBoid(it)) {
            continue;
        }
        if (southWest->insertBoid(it)) {
            continue;
        }
    }

    _divided = true;
}

void QTree::query(float x, float y, float radius, std::vector<Boid *> *list)
{
    if (!boundary.intersect(Boundary(x, y, radius * 2, radius * 2))) {
        return;
    } else {
        if (!_divided) {
            for (auto it : boids) {
                THEcount += 1;
                if (sqrt(pow(it->getPositionX() - (x), 2) + pow(it->getPositionY() - (y), 2)) < radius) {
                    list->push_back(it);
                }
            }
        } else {
            northEst->query(x, y, radius, list);
            northWest->query(x, y, radius, list);
            southEst->query(x, y, radius, list);
            southWest->query(x, y, radius, list);
        }
    }
}

// clean function to rework
void QTree::cleanTree()
{
    if (_divided) {

        boids.clear();
        
        delete northEst;
        delete northWest;
        delete southEst;
        delete southWest;
        _divided = false;
    } else {
        boids.clear();
        return;
    }
}

void QTree::showBoundary()
{
    if (_divided) {
        northEst->showBoundary();
        northWest->showBoundary();
        southEst->showBoundary();
        southWest->showBoundary();
    }
    _win->draw(boundary.shaped);
}