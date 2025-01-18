SRCPATH = ./src/
OBJPATH = ./obj/

SRC =	$(SRCPATH)main.cpp\
		$(SRCPATH)parse.cpp\
		$(SRCPATH)route.cpp\
		$(SRCPATH)vserv.cpp\
		$(SRCPATH)Server.cpp\
		$(SRCPATH)request.cpp\
		$(SRCPATH)response.cpp\
		$(SRCPATH)cgiSession.cpp

OBJ = $(SRC:$(SRCPATH)%.cpp=$(OBJPATH)%.o)

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g3

NAME = server

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

$(OBJPATH)%.o: $(SRCPATH)%.cpp
	@mkdir -p $(OBJPATH)
	$(CC) -c $< -o $@ $(CFLAGS)

clean :
	rm -rf $(OBJPATH)

fclean : clean
	rm -f $(NAME)

re : fclean
	make all

run: $(NAME)
	valgrind  --track-fds=yes --leak-check=full --show-leak-kinds=all ./$(NAME)

test-parsing: $(NAME)
	./tester/parsing.sh

test-requests: $(NAME)
	./tester/requests.sh

test-all: test-parsing test-requests

.PHONY : all clean fclean re test test-parsing test-requests test-all run