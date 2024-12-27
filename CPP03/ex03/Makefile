# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/15 15:47:31 by fgranger          #+#    #+#              #
#    Updated: 2024/08/15 16:01:52 by fgranger         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = DiamondTrap
PATH_SRC = ./
SRC = $(PATH_SRC)main.cpp $(PATH_SRC)ClapTrap.cpp $(PATH_SRC)ScavTrap.cpp $(PATH_SRC)FragTrap.cpp $(PATH_SRC)DiamondTrap.cpp
OBJ_DIR = ./obj/
OBJ = $(patsubst $(PATH_SRC)%.cpp, $(OBJ_DIR)%.o, $(SRC))
CPP = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -Wshadow

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