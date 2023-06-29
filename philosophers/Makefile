# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/19 14:38:51 by chanwoki          #+#    #+#              #
#    Updated: 2023/06/29 17:41:17 by chanwoki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=philo
CFLAGS=-Wall -Wextra -Werror


AR=ar

ARFLAGS=rcsv

RM=rm -f

SRC_FILES=main.c ft_split.c check_argc.c utils.c set_philo.c

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
