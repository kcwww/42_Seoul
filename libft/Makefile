# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanwoki <chanwoki@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 14:14:33 by chanwoki          #+#    #+#              #
#    Updated: 2022/11/11 18:33:51 by chanwoki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_FILES = ft_bzero.c ft_memset.c ft_strlen.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_isalpha.c \
ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strncmp.c ft_toupper.c ft_tolower.c

OBJECTS = $(SRC_FILES:.c=.o)

CC = gcc -Wall -Wextra -Werror

HEADER = .

all : $(NAME)

$(NAME) : $(OBJECTS)
	ar rscv libft.a $(OBJECTS)

%.o : %.c
	$(CC) -I $(HEADER) -c $< -o $@

clean :
	rm -rf $(OBJECTS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
