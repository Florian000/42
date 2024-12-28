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

NAME		=	pipex #Modify the name of the programm

DIR_SRCS	=	./srcs/
LIBFT_DIR	=	./libft/
LIBFT_LIB	=	$(LIBFT_DIR)libft.a
SRCS 		=	$(DIR_SRCS)main.c \
				$(DIR_SRCS)cmd.c \

OBJS		=	$(SRCS:.c=.o)
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

.c.o :	
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
			@echo "\033[1;34m\nCOMPILING $(LIBFT_PATH)\n"
			@echo "\033[0;30m"
			@make -C $(LIBFT_DIR)
			@echo "\033[1;32mLIBFT_lib created ! \n"
			@echo "\033[1;34m\nCOMPILING $(NAME)..\n"
			@echo "\033[0;30m"
			$(CC) $(OBJS) $(LIBFT_LIB) -o $(NAME)
			@clear
			@echo "\033[1;32m$(NAME) created ! \n"

all:		$(NAME)

clean:
			@echo "\033[1;31mDeleting objects files in $(LIBFT_PATH)...\n"
			@echo "\033[0;30m"
			$(MAKE) clean -C $(LIBFT_DIR)
			@echo "\033[1;32mLibft objects files deleted\n"
			@echo "\033[1;31mDeleting objects files in $(DIR_SRCS)...\n"
			@echo "\033[0;30m"
			rm -rf $(OBJS)
			@clear
			@echo "\033[1;32mclean perfectly executed !\n"

fclean:		clean
			@echo "\033[1;31mDeleting objects file in $(LIBFT_PATH)...\n"
			@echo "\033[0;30m"
			$(MAKE) fclean -C $(LIBFT_DIR)
			rm -rf $(NAME)
			@clear
			@echo "\033[1;32mfclean perfectly executed !\n"

re:			fclean all

.PHONY:		all clean fclean re




	
