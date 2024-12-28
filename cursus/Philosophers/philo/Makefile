# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 16:09:48 by fgranger          #+#    #+#              #
#    Updated: 2024/01/13 15:43:27 by fgranger         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Makefile first compiling Libft and then the programm with Lift library included

NAME		=	philo #Modify the name of the programm

DIR_SRCS	=	./
SRCS 		=	$(DIR_SRCS)main.c \
				$(DIR_SRCS)utils.c \
				$(DIR_SRCS)clean.c \
				$(DIR_SRCS)safe_functions.c \
				$(DIR_SRCS)init.c \
				$(DIR_SRCS)dinner.c \
				$(DIR_SRCS)utils_2.c \
				$(DIR_SRCS)monitoring.c \
				$(DIR_SRCS)get_set.c \
				$(DIR_SRCS)parser.c

OBJS		=	$(SRCS:.c=.o)
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -pthread

.c.o :	
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
			@echo "\033[1;34m\nCOMPILING $(NAME)..\n"
			@echo "\033[0;30m"
			$(CC) $(OBJS) -o $(NAME)
			@clear
			@echo "\033[1;32m$(NAME) created ! \n"

all:		$(NAME)

clean:
			@echo "\033[1;31mDeleting objects files in $(DIR_SRCS)...\n"
			@echo "\033[0;30m"
			rm -rf $(OBJS)
			@clear
			@echo "\033[1;32mclean perfectly executed !\n"

fclean:		clean
			rm -rf $(NAME)
			@clear
			@echo "\033[1;32mfclean perfectly executed !\n"

re:			fclean all

.PHONY:		all clean fclean re




	
