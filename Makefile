##
## EPITECH PROJECT, 2021
## Mini-Pacman
## File description:
## Makefile
##

SRC			=	src/main.cpp		\
				src/Boid.cpp		\
				src/Core.cpp		\
				src/MathTools.cpp	\

CXXFLAGS 	=	-Wall -Wextra -lsfml-graphics -lsfml-window -lsfml-system
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
