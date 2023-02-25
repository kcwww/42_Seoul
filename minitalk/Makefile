# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/19 14:38:51 by chanwoki          #+#    #+#              #
#    Updated: 2023/02/25 20:09:02 by chanwoki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=server
NAME2=client

BONUS=server_bonus
BONUS2=client_bonus

CFLAGS=-Wall -Wextra -Werror

FT_PRINTF=ft_printf
LIB_PRINTF=libftprintf.a

FT=ftprintf

AR=ar

ARFLAGS=rcsv

RM=rm -f

SERVER_SRC_FILES=server.c
CLIENT_SRC_FILES=client.c

BONUS_SRC_FILES =

SERVER_OBJECTS = $(SERVER_SRC_FILES:.c=.o)
CLIENT_OBJECTS = $(CLIENT_SRC_FILES:.c=.o)

BONUS_OBJECTS = $(BONUS_SRC_FILES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS)
	make -C $(FT_PRINTF)
	$(CC) $(CFLAGS) -L $(FT_PRINTF) -l $(FT) $(SERVER_SRC_FILES) -o $(NAME)
	$(CC) $(CFLAGS) -L $(FT_PRINTF) -l $(FT) $(CLIENT_SRC_FILES) -o $(NAME2)

clean :
	make clean -C $(FT_PRINTF)
	$(RM) $(OBJECTS) $(BONUS_OBJECTS)

fclean : clean
	make fclean -C $(FT_PRINTF)
	rm -rf $(NAME) $(NAME2) $(LIB_PRINTF) $(BONUS)

re : fclean all

ft_printf :
	make all -C $(FT_PRINTF)/

bonus : $(NAME)
	$(CC) $(CFLAGS) -L $(FT_PRINTF) -l $(FT) $(BONUS_SRC_FILES) -o $(BONUS)
	$(CC) $(CFLAGS) -L $(FT_PRINTF) -l $(FT) $(BONUS_SRC_FILES) -o $(BONUS2)

.PHONY : all clean fclean re ft_printf bonus
