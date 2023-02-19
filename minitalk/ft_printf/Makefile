# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 18:48:59 by chanwoki          #+#    #+#              #
#    Updated: 2022/11/24 19:26:22 by chanwoki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

CFLAGS=-Wall -Wextra -Werror

LIBFT=libft
LIBFT_NAME=libft.a

INCLUDE=-I ./$(LIBFT)

AR=ar

ARFLAGS=rcsv

RM=rm -f

SRC_FILES = ft_printf.c ft_printhex.c ft_printpointer.c ft_itoahex.c ft_itop.c \
ft_printstr.c ft_printint.c ft_printchar.c ft_printuint.c ft_uitoa.c ft_putchar.c ft_putstr.c

OBJECTS = $(SRC_FILES:.c=.o)


all : $(NAME)

$(NAME) : $(OBJECTS)
	make $(LIBFT)
	cp ./$(LIBFT)/$(LIBFT_NAME) $(NAME)
	$(AR) $(ARFLAGS) $@ $(OBJECTS)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean :
	make clean -C $(LIBFT)
	$(RM) $(OBJECTS)
	rm -rf $(OBJECTS)

fclean : clean
	make fclean -C $(LIBFT)
	rm -rf $(NAME)

re : fclean all

libft :
	make all -C $(LIBFT)/

.PHONY : all clean fclean re libft
