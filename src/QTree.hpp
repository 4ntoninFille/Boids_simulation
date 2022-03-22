/*
** EPITECH PROJECT, 2022
** Boids_simulation
** File description:
** QTree
*/

#ifndef QTREE_HPP_
#define QTREE_HPP_


#include "Boundary.hpp"
#include "Boid.hpp"

class Boid;

class QTree {
public:
    QTree(Boundary boundry, sf::RenderWindow *win);
    ~QTree();

    bool insertBoid(Boid *newBoid);

    QTree *northWest;
    QTree *northEst;
    QTree *southWest;
    QTree *southEst;

    Boundary            boundary;
    std::vector<Boid *> boids;


    void                query(float x, float y, float range, std::vector<Boid *> *boidsFind);
    void                showBoundary();
    void                cleanTree();

    int                 maxboids;

protected:
private:
    void _division();

    bool                _divided;
    sf::RenderWindow    *_win;
};

#endif /* !QTREE_HPP_ */