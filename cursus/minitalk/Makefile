# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgranger <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 16:09:48 by fgranger          #+#    #+#              #
#    Updated: 2022/11/12 17:20:22 by fgranger         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Makefile first compiling Libft and then the programm with Lift library included

NAME_client = client
NAME_server = server
LIBFT_DIR   = ./libft/
LIBFT_LIB   = $(LIBFT_DIR)libft.a
SRCS_client = client.c
SRCS_server = server.c

OBJS = $(SRCS_client:.c=.o)
OBJS_server = $(SRCS_server:.c=.o)
CC   = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I includes
RM = rm -f

.c.o:	
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME_client) $(NAME_server)

$(NAME_client): $(OBJS)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) $(LIBFT_LIB) -o $(NAME_client)
	@clear
$(NAME_server): $(OBJS_server)
	@make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS_server) $(INCLUDE) $(LIBFT_LIB) -o $(NAME_server)
	@clear
clean:
	@make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS) $(OBJS_server)
	@clear
fclean: clean
	@make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME_client) $(NAME_server)
	@clear
re: fclean all

.PHONY: all clean fclean re



	
