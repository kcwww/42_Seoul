# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/23 13:48:35 by chanwoki          #+#    #+#              #
#    Updated: 2023/09/23 13:52:29 by chanwoki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC_FILES = phonebook.cpp

OBJ_FILES = $(SRC_FILES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	c++ $(CPPFLAGS) -o $(NAME) $(OBJ_FILES)

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re
