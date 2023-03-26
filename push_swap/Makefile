# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 18:48:59 by chanwoki          #+#    #+#              #
#    Updated: 2023/03/27 02:42:28 by chanwoki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap

CFLAGS=-Wall -Wextra -Werror

LIBFT=libft
LIBFT_NAME=libft.a

AR=ar

ARFLAGS=rcsv

RM=rm -f

SRC_FILES=push_swap.c check_lst.c ft_dequeclear.c ft_dequenew.c game_rule.c game_rule2.c \
check_int.c check_arg.c ft_strcmp.c init_deque.c check_sorting.c set_pivot.c \
ft_dequesize.c sort_three.c greeding.c choose_greed.c ft_rules.c counting_rules.c \
count_rule_num.c execute_pa.c ex_pa_rules.c

OBJECTS = $(SRC_FILES:.c=.o)

FT = ft

all : $(NAME)

$(NAME) : $(OBJECTS)
	make -C $(LIBFT)
	cp ./$(LIBFT)/$(LIBFT_NAME) ./
	$(CC) $(CFLAGS) -L . -l $(FT) $(SRC_FILES) -o $(NAME)

clean :
	make clean -C $(LIBFT)
	$(RM) $(OBJECTS)
	rm -rf $(OBJECTS)

fclean : clean
	make fclean -C $(LIBFT)
	rm -rf $(NAME) $(LIBFT_NAME)

re :
	make fclean
	make all

libft :
	make all -C $(LIBFT)/

.PHONY : all clean fclean re libft
