# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgranger <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 14:58:42 by fgranger          #+#    #+#              #
#    Updated: 2022/08/23 16:18:55 by fgranger         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS = ${SRCS:.c=.o}
NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

.c.o: 
	 ${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ./includes

${NAME}: ${OBJS}
		ar rc ${NAME} ${OBJS}

all:	${NAME}

clean:
			${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY:		all clean fclean re
