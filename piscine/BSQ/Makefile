SRCS	= srcs/main.c srcs/ft_map.c srcs/ft_free.c srcs/ft_helper.c srcs/ft_print_map.c srcs/ft_bsq.c srcs/ft_check.c srcs/ft_strings.c

OBJS	= ${SRCS:.c=.o}

NAME	= bsq

CC	= gcc

RM = rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I includes

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
