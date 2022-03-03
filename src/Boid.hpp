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

class Core;

class Boid : public MathTools {
    public:
        Boid(Core &coreRef, float x, float y);
        ~Boid();

        void update();
        void draw();

        sf::Sprite      spriteBoid;

    protected:
    private:
        void align(std::vector<Boid *> boids);
        void edge();

        sf::Texture         _textureBoid;

        Core *              _coreRef;
        sf::Vector2f        _position;
        sf::Vector2f        _dir;
        sf::Vector2f        _acceleration;
};

#endif /* !BOID_HPP_ */