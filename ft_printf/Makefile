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

LIB_DIR=./libft/

LIB_NAME=ft

LIB=$(LIB_DIR)lib$(LIB_NAME).a

INCLUDE=-I ./libft

AR=ar

ARFLAGS=rcsv

RM=rm -f

SRC_FILES = ft_printf.c

OBJECTS = $(SRC_FILES:.c=.o)


all : $(NAME)

$(NAME) : $(LIB) $(OBJECTS)
	cp $(LIB) $(NAME)
	$(AR) $(ARFLAGS) $@ $(OBJECTS)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean :
	rm -rf $(OBJECTS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

bonus: $(OBJECTS)
	ar rcsv $(NAME) $(OBJECTS)

# libft complie

libft :
		$(MAKE) -C $(LIB_DIR) all

clean :
		$(MAKE) -C ./libft clean

fclean :
		$(MAKE) -C ./libft fclean
		rm -rf $(NAME)

re : fclean all


.PHONY : all clean fclean re bonus libft
