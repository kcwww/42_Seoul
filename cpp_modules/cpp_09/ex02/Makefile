# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanwookim <chanwookim@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/20 16:25:42 by chanwoki          #+#    #+#              #
#    Updated: 2024/06/03 01:50:12 by chanwookim       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = PmergeMe

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC_FILES = main.cpp PmergeMe.cpp

OBJ_FILES = $(SRC_FILES:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	c++ $(CPPFLAGS) -o $(NAME) $(OBJ_FILES)


clean :
	rm -f $(OBJ_FILES)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
