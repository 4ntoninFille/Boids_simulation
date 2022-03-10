/*
** EPITECH PROJECT, 2022
** Boids_simulation
** File description:
** Core
*/

#include "Core.hpp"

int THEcount = 0;

Core::Core(sf::RenderWindow *window)
    :   _window(window)
{
    gridTree = new QTree(Boundary(WIN_WIDTH / 2, WIN_HEIGHT / 2, WIN_WIDTH, WIN_HEIGHT), window);
    _visualQTree = false;
    _pause = false;

    srand (static_cast <unsigned> (time(0)));
    for (int i = 0; i < 500; i++) {
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
    _time = _clock.getElapsedTime();
    if (_time.asMilliseconds() < 10)
        return;

    gridTree->cleanTree();
    for (auto it : _boids) {
        gridTree->insertBoid(it);
    }

    for (auto it : _boids) {
        if (!_pause) {
            it->update();
        }
    }

    //// DEBUG SECTION ////
    
    // std::vector<Boid *> listboid;
    // gridTree->query(sf::Mouse::getPosition(*_window).x, sf::Mouse::getPosition(*_window).y, 100, &listboid);

    // for (auto it : listboid) {
    //     it->bodyCircle.setFillColor({0, 255, 0, 255});
    //     std::cout << it->_id << std::endl;
    // }
    // std::cout << "---------------" << std::endl;
    // for (auto it : _boids) {
    //     if (distance({(float)sf::Mouse::getPosition(*_window).x, (float)sf::Mouse::getPosition(*_window).y}, {it->getPositionX(), it->getPositionY()}) < 100) {
    //         it->bodyCircle.setFillColor({0, 0, 255, 255});
    //         std::cout << it->_id << std::endl;
    //     }
    // }
    // std::cout << "------------- FIN ------------" << std::endl;

    //////////////////////
    
    std::cout << THEcount << std::endl;
    THEcount = 0;
    _clock.restart();
}

void Core::simuDraw()
{
    for (auto it : _boids) {
        it->draw();
    }
    if (_visualQTree)
        gridTree->showBoundary();
}

void Core::events()
{
    static int ide = 0;
    while (_window->pollEvent(_event)) {
        if (_event.type == sf::Event::MouseButtonPressed) {
            if (_event.mouseButton.button == sf::Mouse::Left) {
                _boids.push_back(new Boid(*this, _event.mouseButton.x, _event.mouseButton.y, ide));
                ide += 1;
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
            if (_event.key.code == sf::Keyboard::Q) {
                if (_visualQTree) {
                    _visualQTree = false;
                } else {
                    _visualQTree = true;
                }
            }
            if (_event.key.code == sf::Keyboard::Space) {
                if (_pause) {
                    _pause = false;
                } else {
                    _pause = true;
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