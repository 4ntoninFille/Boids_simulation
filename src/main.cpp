/*
** EPITECH PROJECT, 2022
** testSfml
** File description:
** main
*/

#include <iostream>

#include "Boid.hpp"
#include "Core.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIN_WIDTH, WIN_HEIGHT), "BOIDS SIMULATION");

    Core simulation(&window);

    simulation.loop();
    return 0;
}