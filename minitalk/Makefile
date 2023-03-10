# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/19 14:38:51 by chanwoki          #+#    #+#              #
#    Updated: 2023/03/10 15:26:06 by chanwoki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=server
NAME2=client

CFLAGS=-Wall -Wextra -Werror

FT_PRINTF=ft_printf
LIB_PRINTF=libftprintf.a

FT=ftprintf

AR=ar

ARFLAGS=rcsv

RM=rm -f

SERVER_SRC_FILES=server.c
CLIENT_SRC_FILES=client.c

SERVER_OBJECTS = $(SERVER_SRC_FILES:.c=.o)
CLIENT_OBJECTS = $(CLIENT_SRC_FILES:.c=.o)


all : $(NAME)

$(NAME) : $(OBJECTS)
	make -C $(FT_PRINTF)
	$(CC) $(CFLAGS) -L $(FT_PRINTF) -l $(FT) $(SERVER_SRC_FILES) -o $(NAME)
	$(CC) $(CFLAGS) -L $(FT_PRINTF) -l $(FT) $(CLIENT_SRC_FILES) -o $(NAME2)

clean :
	make clean -C $(FT_PRINTF)
	$(RM) $(SERVER_OBJECTS) $(CLIENT_OBJECTS)

fclean : clean
	make fclean -C $(FT_PRINTF)
	rm -rf $(NAME) $(NAME2) $(LIB_PRINTF)

re : fclean all

ft_printf :
	make all -C $(FT_PRINTF)/

.PHONY : all clean fclean re ft_printf
