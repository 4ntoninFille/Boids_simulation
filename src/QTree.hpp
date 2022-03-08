/*
** EPITECH PROJECT, 2022
** Boids_simulation
** File description:
** QTree
*/

#ifndef QTREE_HPP_
#define QTREE_HPP_

#define MAXBOID 4

#include "Boundary.hpp"
#include "Boid.hpp"

class Boid;

class QTree {
public:
    QTree(Boundary boundry, sf::RenderWindow *win);
    ~QTree();

    void insertBoid(Boid *newBoid);

    QTree *northWest;
    QTree *northEst;
    QTree *southWest;
    QTree *southEst;

    Boundary            boundary;
    std::vector<Boid *> boids;

    void showBoundary() const;
    void cleanTree();

protected:
private:
    void _division();

    bool                _divided;
    sf::RenderWindow    *_win;
};

#endif /* !QTREE_HPP_ */