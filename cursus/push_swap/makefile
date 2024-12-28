# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 16:09:48 by fgranger          #+#    #+#              #
#    Updated: 2023/12/30 14:22:15 by fgranger         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Makefile first compiling Libft and then the programm with Lift library included

NAME		=	push_swap #Modify the name of the programm
BONUS		= 	checker
DIR_SRCS	=	./srcs/
DIR_BONUS	=	./bonus/
LIBFT_DIR	=	./libft/
LIBFT_LIB	=	$(LIBFT_DIR)libft.a
SRCS 		=	$(DIR_SRCS)main.c \
				$(DIR_SRCS)get_data.c \
				$(DIR_SRCS)stacks.c \
				$(DIR_SRCS)moves_a.c \
				$(DIR_SRCS)moves_b.c \
				$(DIR_SRCS)moves_both.c \
				$(DIR_SRCS)checks.c \
				$(DIR_SRCS)get_meta.c \
				$(DIR_SRCS)sort_stack.c
				
SRCS_BONUS =	$(DIR_BONUS)main.c \
				$(DIR_SRCS)get_data.c \
				$(DIR_SRCS)stacks.c \
				$(DIR_SRCS)moves_a.c \
				$(DIR_SRCS)moves_b.c \
				$(DIR_SRCS)moves_both.c \
				$(DIR_SRCS)checks.c \
				$(DIR_SRCS)get_meta.c \
				$(DIR_SRCS)sort_stack.c 
				
#add all the sources files of the programm here
OBJS		=	$(SRCS:.c=.o)
OBJS_BONUS = ${SRCS_BONUS:.c=.o}
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g

.c.o :	
			$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

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

bonus:		$(OBJS_BONUS)
			@echo "\033[1;34m\nCOMPILING $(LIBFT_PATH)\n"
			@echo "\033[0;30m"
			@make -C $(LIBFT_DIR)
			@echo "\033[1;32mLIBFT_lib created ! \n"
			@echo "\033[1;34m\nCOMPILING $(BONUS)..\n"
			@echo "\033[0;30m"
			$(CC) $(OBJS_BONUS) $(LIBFT_LIB) -o $(BONUS)
			@clear
			@echo "\033[1;32m$(BONUS) created ! \n"
	
clean:
			@echo "\033[1;31mDeleting objects files in $(LIBFT_PATH)...\n"
			@echo "\033[0;30m"
			$(MAKE) clean -C $(LIBFT_DIR)
			@echo "\033[1;32mLibft objects files deleted\n"
			@echo "\033[1;31mDeleting objects files in $(DIR_SRCS)...\n"
			@echo "\033[0;30m"
			rm -rf $(OBJS)
			rm -rf $(OBJS_BONUS)
			@clear
			@echo "\033[1;32mclean perfectly executed !\n"

fclean:		clean
			@echo "\033[1;31mDeleting objects file in $(LIBFT_PATH)...\n"
			@echo "\033[0;30m"
			$(MAKE) fclean -C $(LIBFT_DIR)
			rm -rf $(NAME)
			rm -rf $(BONUS)
			@clear
			@echo "\033[1;32mfclean perfectly executed !\n"

re:			fclean all

.PHONY:		all clean fclean re




	
