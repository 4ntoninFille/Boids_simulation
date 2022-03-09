/*
** EPITECH PROJECT, 2022
** Boids_simulation
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#define WIN_WIDTH 1920
#define WIN_HEIGHT 1080

// #include "Boid.hpp"
#include "QTree.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <vector>

class Boid;
class QTree;


extern int THEcount;

class Core {
    public:
        Core(sf::RenderWindow *window);
        ~Core();

        void loop();

        void simuDraw();
        void simuUpdate();

        sf::RenderWindow *  getWindow() const;
        std::vector<Boid *>   getBoids() const;

        QTree *gridTree;

    protected:
    private:
        void events();

        sf::RenderWindow *  _window;
        sf::Event           _event;
        sf::Clock           _clock;
        sf::Time            _time;

        std::vector<Boid *>   _boids;
};

#endif /* !CORE_HPP_ */