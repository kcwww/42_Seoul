# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcw <kcw@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/23 13:48:35 by chanwoki          #+#    #+#              #
#    Updated: 2023/12/06 09:21:17 by kcw              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = replacer

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC_FILES = main.cpp Replacer.cpp

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
