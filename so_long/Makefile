# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 14:14:33 by chanwoki          #+#    #+#              #
#    Updated: 2023/01/29 18:56:43 by chanwoki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=so_long

CFLAGS=-Wall -Wextra -Werror

LIBFT=libft
LIBFT_NAME=libft.a

AR=ar

ARFLAGS=rcsv

RM=rm -f

SRC_FILES=so_long.c

OBJECTS = $(SRC_FILES:.c=.o)

FT = ft

MLX = mlx

MLXF = -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(OBJECTS)
	make -C $(LIBFT)
	make -C $(MLX)
	$(CC) $(CFLAGS) -L $(LIBFT) -l $(FT) -L $(MLX) -l $(MLX) $(MLXF) $(SRC_FILES) -o $(NAME)
	install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(NAME)

clean :
	make clean -C $(LIBFT)
	make clean -C $(MLX)
	$(RM) $(OBJECTS) libmlx.dylib
	rm -rf $(OBJECTS)

fclean : clean
	make fclean -C $(LIBFT)
	rm -rf $(NAME) $(LIBFT_NAME)

re : fclean all

libft :
	make all -C $(LIBFT)/

.PHONY : all clean fclean re libft