/*
** EPITECH PROJECT, 2022
** testSfml
** File description:
** main
*/

#include <iostream>

#include "Boid.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "TEST");

    Boid boid(&window, 400, 300);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();

        boid.draw();

        window.display(); 
    }
    return 0;
}