# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjodge <mjodge>                            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/11 16:15:28 by mjodge            #+#    #+#              #
#    Updated: 2021/10/11 16:15:32 by mjodge           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
SRC = 			ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c\
				ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c\
				ft_itoa.c ft_memchr.c ft_memcmp.c\
				ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c\
				ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c\
				ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c\
				ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c\
				ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c\
				ft_substr.c ft_tolower.c ft_toupper.c\
				ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c\
				ft_lstdelone.c ft_lstiter.c ft_lstlast.c\
				ft_lstnew.c ft_lstsize.c

OBJ = $(patsubst %.c, %.o, $(SRC))
OBJ_BONUS = $(patsubst %.c, %.o, $(SRC_BONUS))
RM = rm -f

all : $(NAME)

$(NAME) : $(OBJ)
		ar rcs $(NAME) $?

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

bonus :
	@make OBJ="$(OBJ_BONUS)" all

clean : 
	@$(RM) $(OBJ) $(OBJ_BONUS)

fclean : clean
	@$(RM) $(NAME)
re : fclean all
	
.PHONY : all bonus clean fclean re
