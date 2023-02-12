# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 14:14:33 by chanwoki          #+#    #+#              #
#    Updated: 2023/02/12 16:08:37 by chanwoki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=so_long

BONUS=so_long_bonus

CFLAGS=-Wall -Wextra -Werror

LIBFT=libft
LIBFT_NAME=libft.a

AR=ar

ARFLAGS=rcsv

RM=rm -f

SRC_FILES=so_long.c init_so_long.c map_check.c press_key.c check_wall.c draw_map.c \
so_walk.c init_player.c set_so_long.c get_so_long.c error_msg.c dfs_clear.c \
map_error_check.c

BONUS_SRC_FILES = dfs_clear_bonus.c draw_map_bonus.c get_so_long_bonus.c \
init_player_bonus.c init_so_long_bonus.c map_error_check_bonus.c \
octo_bonus.c press_key_bonus.c set_so_long_bonus.c so_long_bonus.c so_walk_bonus.c \
error_msg.c check_wall_bonus.c map_check.c

OBJECTS = $(SRC_FILES:.c=.o)

BONUS_OBJECTS = $(BONUS_SRC_FILES:.c=.o)

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
	$(RM) $(OBJECTS) $(BONUS_OBJECTS) libmlx.dylib

fclean : clean
	make fclean -C $(LIBFT)
	rm -rf $(NAME) $(LIBFT_NAME) $(BONUS)

re : fclean all

libft :
	make all -C $(LIBFT)/

bonus : $(NAME)
	$(CC) $(CFLAGS) -L $(LIBFT) -l $(FT) -L $(MLX) -l $(MLX) $(MLXF) $(BONUS_SRC_FILES) -o $(BONUS)
	install_name_tool -change libmlx.dylib mlx/libmlx.dylib $(BONUS)

.PHONY : all clean fclean re libft bonus
