# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 18:48:59 by chanwoki          #+#    #+#              #
#    Updated: 2022/11/19 17:48:33 by chanwoki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

CFLAGS=-Wall -Wextra -Werror

LIBFT=libft
LIBFT_NAME=libft.a

LIB=$(LIB_DIR)lib$(LIB_NAME).a

INCLUDE=-I ./$(LIBFT)

AR=ar

ARFLAGS=rcsv

RM=rm -f

SRC_FILES = ft_printf.c ft_printhex.c ft_printpointer.c ft_itoahex.c

OBJECTS = $(SRC_FILES:.c=.o)


all : $(NAME)

$(NAME) : $(OBJECTS)
	make all -C $(LIBFT)/
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

bonus: $(OBJECTS)
	ar rcsv $(NAME) $(OBJECTS)


.PHONY : all clean fclean re bonus
