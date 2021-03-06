/*
** EPITECH PROJECT, 2022
** testSfml
** File description:
** Boid
*/

#ifndef BOID_HPP_
#define BOID_HPP_

#include "AssetManager.hpp"
#include "MathTools.hpp"
#include "Core.hpp"

#include <iostream>
#include <unistd.h>


class Core;

class Boid : public MathTools {
    public:
        Boid(Core &coreRef, float x, float y, int id);
        ~Boid();

        void update();
        void draw();

        sf::CircleShape bodyCircle;
        sf::Vertex      *line;

        void addCoefAlignement(float value);
        void addCoefCohesion(float value);
        void addCoefSeparation(float value);

        float getPositionX() const;
        float getPositionY() const;
        int                 _id;

    protected:
    private:
        void align(std::vector<Boid *> boids);
        void edge();

        Core *              _coreRef;
        sf::Vector2f        _position;
        sf::Vector2f        _dir;
        sf::Vector2f        _acceleration;
        float               _maxForce;
        float               _maxSpeed;
        float               _perception;

        float               _coefAlignement;
        float               _coefCohesion;
        float               _coefSeparation;

        int                 _boidSize;
};

#endif /* !BOID_HPP_ */