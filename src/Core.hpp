/*
** EPITECH PROJECT, 2022
** Boids_simulation
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#define WIN_WIDTH 800
#define WIN_HEIGHT 600

#include "Boid.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <vector>

class Boid;

class Core {
    public:
        Core(sf::RenderWindow *window);
        ~Core();

        void loop();

        void simuDraw();
        void simuUpdate();

        sf::RenderWindow *  getWindow() const;
        std::vector<Boid *>   getBoids() const;

    protected:
    private:
        sf::RenderWindow *  _window;
        sf::Event           _event;
        sf::Clock           _clock;
        sf::Time            _time;

        std::vector<Boid *>   _boids;
};

#endif /* !CORE_HPP_ */