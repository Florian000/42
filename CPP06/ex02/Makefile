CC = g++
CFLAGS = -Wall -Wextra -Werror
SRC = main.cpp functions.cpp Base.cpp A.cpp B.cpp C.cpp
OBJ = $(SRC:.cpp=.o)
NAME = identify_real_type

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
