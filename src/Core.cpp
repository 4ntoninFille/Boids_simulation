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
    gridTree = new QTree(Boundary(WIN_WIDTH / 2, WIN_HEIGHT / 2, WIN_WIDTH, WIN_HEIGHT), window);

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
    delete gridTree;
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
    gridTree->cleanTree();
    for (auto it : _boids) {
        gridTree->insertBoid(it);
    }

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
    gridTree->showBoundary();
}

void Core::events()
{
    while (_window->pollEvent(_event)) {
        if (_event.type == sf::Event::MouseButtonPressed) {
            if (_event.mouseButton.button == sf::Mouse::Left) {
                _boids.push_back(new Boid(*this, _event.mouseButton.x, _event.mouseButton.y, -1));
            }
        }

        if (_event.type == sf::Event::KeyPressed) {
            if (_event.key.code == sf::Keyboard::A) {
                for (auto it : _boids) {
                    it->addCoefAlignement(0.1);
                }
            }
            if (_event.key.code == sf::Keyboard::C) {
                for (auto it : _boids) {
                    it->addCoefCohesion(0.1);
                }
            }
            if (_event.key.code == sf::Keyboard::S) {
                for (auto it : _boids) {
                    it->addCoefSeparation(0.1);
                }
            }
        }

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