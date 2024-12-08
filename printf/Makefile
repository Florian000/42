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

NAME		=	libftprintf.a

DIR_SRCS	=	./srcs/
LIBFT_DIR	=	./libft
SRCS 		=	$(DIR_SRCS)ft_printf.c \
				$(DIR_SRCS)functions1.c \
				$(DIR_SRCS)functions2.c \
				$(DIR_SRCS)ft_putnbr.c
OBJS		=	$(SRCS:.c=.o)
INCLUDES	=	-I ./includes
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror

.c.o :	
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME):	$(OBJS)
			$(MAKE) -C $(LIBFT_DIR)
			cp $(LIBFT_DIR)/libft.a $(NAME)
			ar -rcs $(NAME) $(OBJS) 

all:		$(NAME)

clean:
			$(MAKE) clean -C $(LIBFT_DIR)
			rm -rf $(OBJS) $(OBJS_BONUS)

fclean:		clean
			$(MAKE) fclean -C $(LIBFT_DIR)
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re




	
