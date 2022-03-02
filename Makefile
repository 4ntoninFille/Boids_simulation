##
## EPITECH PROJECT, 2021
## Mini-Pacman
## File description:
## Makefile
##

SRC			=	src/main.cpp	\
				src/Boid.cpp	\

CXXFLAGS 	=	-Wall -Wextra -lsfml-graphics -lsfml-window -lsfml-system -g3
NAME 		= 	boids_simulation

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	g++ -o $(NAME) $(OBJ) $(CXXFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re