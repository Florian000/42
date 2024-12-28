# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 15:50:42 by yuewang           #+#    #+#              #
#    Updated: 2024/04/21 22:00:28 by fgranger         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########## ARGUMENTS ###########

NAME	  = minishell
CC		  = cc
CFLAG	  = -Wall -Wextra -Werror
LDFLAGS   = -lreadline
CPPFLAGS  = -I inc/ -I src/libft/ -I/usr/include/readline
INC_LIBFT = -I src/libft/
INC		  = -I inc/
RM		  = rm -f

########## SOURCES ###########

LIBFT_DIR 	= src/libft/
LIBFT		= $(LIBFT_DIR)libft.a

SRC_DIR    = src/
SRC_FILES = src/clean2.c \
			src/clean.c \
			src/error.c \
			src/minishell.c \
			src/pathname.c \
			src/safe_functions.c \
			src/utils_path.c \
			src/execute/execute.c \
			src/execute/execution_tools.c \
			src/execute/redirection.c \
			src/execute/redir_files_single.c \
			src/parsing/extract_token.c \
			src/parsing/extract_token_helper.c \
			src/parsing/file_list.c \
			src/parsing/handle_quotes.c \
			src/parsing/parsing.c \
			src/parsing/process_init.c \
			src/parsing/prompt_init.c \
			src/parsing/shell_init.c \
			src/parsing/token_expansion.c \
			src/parsing/tokenization.c \
			src/parsing/tokenization_helper.c \
			src/signal/signal_handler.c \
			src/execute/built-in/cd.c \
			src/execute/built-in/echo.c \
			src/execute/built-in/env.c \
			src/execute/built-in/env_tools.c \
			src/execute/built-in/exit.c \
			src/execute/built-in/export.c \
			src/execute/built-in/print_export.c \
			src/execute/built-in/pwd.c \
			src/execute/built-in/unset.c
			
 #wildcard to be changed to sources filenames
OBJ_DIR    = obj/
OBJ 	   = $(SRC_FILES:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

########## RULES ###########

all : $(NAME)

$(LIBFT) :
	$(MAKE) -C $(LIBFT_DIR)

$(NAME) : $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS) $(LIBFT)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(@D)
	$(CC) $(CPPFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)
	$(RM) -r $(OBJ_DIR)

fclean_libft :
	$(MAKE) -C $(LIBFT_DIR) fclean

fclean : clean fclean_libft
	$(RM) $(NAME)

re : fclean all

leaks: all
	valgrind -s --leak-check=full --show-leak-kinds=all --track-fds=yes --suppressions=del.supp  ./minishell

.PHONY : all clean fclean re fclean_libft