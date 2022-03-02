/*
** EPITECH PROJECT, 2022
** testSfml
** File description:
** main
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "TEST");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();

        window.display(); 
    }
    return 0;
}