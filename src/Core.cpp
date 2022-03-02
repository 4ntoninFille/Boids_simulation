/*
** EPITECH PROJECT, 2022
** Boids_simulation
** File description:
** Core
*/

#include "Core.hpp"

Core::Core(sf::RenderWindow *window)
    :   _window(window)
{
    Boid *adam = new Boid(window, 400, 300);
    _boids.push_back(adam);
}

Core::~Core()
{
    for (auto it : _boids) {
        delete it;
    }
}

void Core::loop()
{
    while (_window->isOpen()) {
        sf::Event event;
        while (_window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                _window->close();
                return;
            }
        }

        _window->clear();

        this->simuUpdate();
        this->simuDraw();

        _window->display(); 
    }
}

void Core::simuUpdate()
{
    for (auto it : _boids) {
        it->update();
    }
}

void Core::simuDraw()
{
    for (auto it : _boids) {
        it->draw();
    }
}