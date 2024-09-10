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

NAME		=	libft.a

DIR_SRCS	=	libft

SRCS 		=	ft_atoi.c \
				ft_bzero.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_calloc.c \
				ft_lstadd_back.c \
				ft_lstadd_front.c \
				ft_lstclear.c \
				ft_lstdelone.c \
				ft_lstiter.c \
				ft_lstlast.c \
				ft_lstmap.c \
				ft_lstnew.c \
				ft_lstsize.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_memset.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strmapi.c \
				ft_itoa.c \
				ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_split.c \
				ft_strchr.c \
				ft_strdup.c \
				ft_striteri.c \
				ft_strjoin.c \
				ft_strlen.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strtrim.c \
				ft_substr.c \
				ft_tolower.c \
				ft_toupper.c \

BONUS		=	ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c \

OBJS		=	$(SRCS:.c=.o)

OBJS_BONUS	=	$(BONUS:.c=.o)

INCLUDES	=	-I includes

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

.c.o :	
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME):	$(OBJS)
			ar -rcs $(NAME) $(OBJS)

all:		$(NAME)

bonus:		$(OBJS) $(OBJS_BONUS)
			ar rcs $(NAME) $(OBJS) $(OBJS_BONUS)

clean:
			rm -rf $(OBJS) $(OBJS_BONUS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re




	
