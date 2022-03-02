/*
** EPITECH PROJECT, 2022
** testSfml
** File description:
** Boid
*/

#ifndef BOID_HPP_
#define BOID_HPP_

#include "AssetManager.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <math.h>

#include <iostream>

class Boid {
    public:
        Boid(sf::RenderWindow *window, float x, float y);
        ~Boid();

        void update();
        void draw();

        sf::Sprite      spriteBoid;

    protected:
    private:
        sf::Texture         _textureBoid;
        sf::RenderWindow *  _window;
        sf::Vector2f        _position;
        sf::Vector2f        _dir;
};

#endif /* !BOID_HPP_ */