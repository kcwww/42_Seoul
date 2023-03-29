# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanwookim <chanwookim@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 18:48:59 by chanwoki          #+#    #+#              #
#    Updated: 2023/03/30 03:08:39 by chanwookim       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap
BONUS=Checker

CFLAGS=-Wall -Wextra -Werror

LIBFT=libft
LIBFT_NAME=libft.a

AR=ar

ARFLAGS=rcsv

RM=rm -f

SRC_FILES=push_swap.c check_lst.c ft_dequeclear.c ft_dequenew.c game_rule.c \
game_rule2.c check_int.c check_arg.c ft_strcmp.c init_deque.c check_sorting.c \
set_pivot.c ft_dequesize.c sort_three.c greeding.c choose_greed.c ft_rules.c \
counting_rules.c count_rule_num.c execute_pa.c ex_pa_rules.c

BONUS_PATH=push_swap_bonus/
BONUS_SRC_FILES=push_swap_bonus.c check_arg_bonus.c check_sorting_bonus.c \
ft_dequeclear_bonus.c check_str_bonus.c ft_strcmp_bonus.c check_lst_bonus.c \
check_rules_bonus.c ft_dequenew_bonus.c ft_rules_bonus.c game_rule_bonus.c \
game_rule2_bonus.c init_deque_bonus.c

BONUS_WITH_PATH=$(addprefix $(BONUS_PATH), $(BONUS_SRC_FILES))

OBJECTS = $(SRC_FILES:.c=.o)
BONUS_OBJECTS = $(BONUS_SRC_FILES:.c=.o)

FT = ft

all : $(NAME)

$(NAME) : $(OBJECTS)
	make -C $(LIBFT)
	cp ./$(LIBFT)/$(LIBFT_NAME) ./
	$(CC) $(CFLAGS) -L . -l $(FT) $(SRC_FILES) -o $(NAME)

clean :
	make clean -C $(LIBFT)
	$(RM) $(OBJECTS)
	$(RM) $(addprefix $(BONUS_PATH), $(BONUS_OBJECTS))
	rm -rf $(OBJECTS)

fclean : clean
	make fclean -C $(LIBFT)
	rm -rf $(NAME) $(LIBFT_NAME) $(BONUS)

re :
	make fclean
	make all
	
bonus :
	make all
	$(CC) $(CFLAGS) -g3 -fsanitize=address -L . -l $(FT) -I $(BONUS_PATH) $(BONUS_WITH_PATH) -o $(BONUS)

libft :
	make all -C $(LIBFT)/


.PHONY : all clean fclean re libft bonus
