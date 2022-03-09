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

    if (boids.size() < MAXBOID && !_divided) {
        boids.push_back(newBoid);
        return;
    }

    // if (boids.size() > MAXBOID) {
    //     return;
    // }

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

    for (auto it : boids) {
        northEst->insertBoid(it);
        northWest->insertBoid(it);
        southEst->insertBoid(it);
        southWest->insertBoid(it);
    }
    boids.clear();

    _divided = true;
}

void QTree::query(float x, float y, float radius, std::vector<Boid *> *list)
{
    if (!boundary.intersect(x, y, radius * 2, radius * 2)) {
        return;
    } else {
        for (auto it : boids) {
            THEcount += 1;
            if (sqrt(pow(it->getPositionX() - x, 2) + pow(it->getPositionY() - y, 2)) <= radius) {
                list->push_back(it);
                // it->spriteBoid.setColor({0, 255, 0, 255});
            }
        }

        if (_divided) {
            northEst->query(x, y, radius, list);
            northWest->query(x, y, radius, list);
            southEst->query(x, y, radius, list);
            southWest->query(x, y, radius, list);
        }
    }

    // sf::CircleShape shape(radius);
    // shape.setOrigin(radius, radius);
    // shape.setPosition({x, y});
    // shape.setOutlineThickness(1);
    // shape.setOutlineColor({255, 0, 0, 255});
    
    // shape.setFillColor({0, 0, 0, 255});
    // _win->draw(shape);
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