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
    srand (static_cast <unsigned> (time(0)));
    for (int i = 0; i < 400; i++) {
        Boid *tmp = new Boid(*this, rand() % WIN_WIDTH, rand() % WIN_HEIGHT, i);
        _boids.push_back(tmp);
    }

    _clock.restart();
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
        events();

        _window->clear();

        this->simuUpdate();
        this->simuDraw();

        _window->display(); 
    }
}

void Core::simuUpdate()
{
    _time = _clock.getElapsedTime();
    if (_time.asMilliseconds() < 10)
        return;
    _clock.restart();
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

void Core::events()
{
    while (_window->pollEvent(_event))
    {
        if (_event.type == sf::Event::Closed) {
            _window->close();
            return;
        }
    }
}

sf::RenderWindow *Core::getWindow() const
{
    return _window;
}

std::vector<Boid *> Core::getBoids() const
{
    return _boids;
}