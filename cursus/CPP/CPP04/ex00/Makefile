# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/15 15:47:31 by fgranger          #+#    #+#              #
#    Updated: 2024/08/15 16:33:39 by fgranger         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = animal
PATH_SRC = ./src/
SRC = $(PATH_SRC)Animal.cpp $(PATH_SRC)Cat.cpp $(PATH_SRC)main.cpp $(PATH_SRC)Dog.cpp $(PATH_SRC)WrongCat.cpp $(PATH_SRC)WrongAnimal.cpp 
OBJ_DIR = ./obj/
OBJ = $(patsubst $(PATH_SRC)%.cpp, $(OBJ_DIR)%.o, $(SRC))
CPP = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(PATH_SRC)%.cpp | $(OBJ_DIR)
	$(CPP) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CPP) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re