# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/19 14:38:51 by chanwoki          #+#    #+#              #
#    Updated: 2023/06/21 14:33:06 by chanwoki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=philo
CFLAGS=-Wall -Wextra -Werror


AR=ar

ARFLAGS=rcsv

RM=rm -f

SRC_FILES=server.c

SRC_OBJECTS = $(SRC_FILES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) $(SRC_FILES) -o $(NAME)

clean :
	$(RM) $(SRC_OBJECTS)

fclean : clean
	rm -rf $(NAME)

re : fclean all


.PHONY : all clean fclean re
