# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 16:09:48 by fgranger          #+#    #+#              #
#    Updated: 2024/01/01 21:15:18 by fgranger         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Makefile first compiling Libft and then the programm with Lift library included

#Program name
NAME	= fractol

DIR_SRCS	=	srcs/
LIBFT_DIR = libft/
LIBFT_LIB = $(LIBFT_DIR)libft.a
MLX_DIR = minilibx-linux/
MLX_LIB = $(MLX_DIR)libmlx.a
SRCS		=	$(DIR_SRCS)main.c \
				$(DIR_SRCS)events.c \
				$(DIR_SRCS)math.c \
				$(DIR_SRCS)init.c \
				$(DIR_SRCS)utils.c \
				$(DIR_SRCS)fractals.c \
				$(DIR_SRCS)print_fractol.c 

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
INC			=	-I includes

OBJS		= $(SRCS:.c=.o)

.c.o :	
			$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			@echo "\033[1;34m\nCOMPILING $(LIBFT_PATH)\n"
			@echo "\033[0;30m"
			@make -C $(LIBFT_DIR)
			@echo "\033[1;32mLIBFT_lib created ! \n"
			@echo "\033[1;34m\nCOMPILING $(MLX_PATH)\n"
			@echo "\033[0;30m"
			@make -C $(MLX_DIR)
			@echo "\033[1;32mMLX_lib created ! \n"
			@echo "\033[1;34m\nCOMPILING $(NAME)..\n"
			@echo "\033[0;30m"
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(MLX_LIB) -o $(NAME) -lXext -lX11 -lm
			@clear
			@echo "\033[1;32m$(NAME) created ! \n"

clean:
			@echo "\033[1;31mDeleting objects files in $(LIBFT_PATH)...\n"
			@echo "\033[0;30m"
			$(MAKE) clean -C $(LIBFT_DIR)
			$(MAKE) clean -C $(MLX_DIR)
			@echo "\033[1;32mLibft objects files deleted\n"
			@echo "\033[1;31mDeleting objects files in $(DIR_SRCS)...\n"
			@echo "\033[0;30m"
			rm -rf $(OBJS)
			@clear
			@echo "\033[1;32mclean perfectly executed !\n"

fclean:		clean
			@echo "\033[1;31mDeleting objects file in $(LIBFT_PATH)...\n"
			@echo "\033[0;30m"
			rm -rf $(LIBFT_LIB)
			rm -rf $(NAME)
			rm -rf $(MLX_LIB)
			@clear
			@echo "\033[1;32mfclean perfectly executed !\n"

re:			fclean all

.PHONY:		all clean fclean re
