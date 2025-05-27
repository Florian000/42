# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/29 17:19:27 by fgranger          #+#    #+#              #
#    Updated: 2025/01/27 17:55:39 by fgranger         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe
PATH_SRC = ./src/
SRC = $(PATH_SRC)main.cpp $(PATH_SRC)PmergeMe.cpp
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