# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/20 16:25:42 by chanwoki          #+#    #+#              #
#    Updated: 2024/01/22 17:28:22 by chanwoki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = DynamicCast

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC_FILES = main.cpp Base.cpp

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
