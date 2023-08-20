# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/19 14:38:51 by chanwoki          #+#    #+#              #
#    Updated: 2023/08/20 16:11:13 by chanwoki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=philo
CFLAGS=-Wall -Wextra -Werror


AR=ar

ARFLAGS=rcsv

RM=rm -f

SRC_FILES=main.c ft_split.c check_argc.c utils.c set_philo.c free_philo.c start.c \
philo_even.c philo_odd.c philo_do.c check_philo.c

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
