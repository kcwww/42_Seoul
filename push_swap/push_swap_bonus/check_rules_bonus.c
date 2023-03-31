/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rules_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcw <kcw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 02:20:22 by chanwookim        #+#    #+#             */
/*   Updated: 2023/03/31 14:01:43 by kcw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	check_one(char *rule, int *re)
{
	if (ft_strcmp(rule, "sa") == 0)
		*re = 1;
	else if (ft_strcmp(rule, "sb") == 0)
		*re = 1;
	else if (ft_strcmp(rule, "ss") == 0)
		*re = 1;
	else if (ft_strcmp(rule, "pb") == 0)
		*re = 1;
	else if (ft_strcmp(rule, "pa") == 0)
		*re = 1;
}

static void	check_two(char *rule, int *re)
{
	if (ft_strcmp(rule, "rb") == 0)
		*re = 1;
	else if (ft_strcmp(rule, "ra") == 0)
		*re = 1;
	else if (ft_strcmp(rule, "rr") == 0)
		*re = 1;
	else if (ft_strcmp(rule, "rra") == 0)
		*re = 1;
	else if (ft_strcmp(rule, "rrb") == 0)
		*re = 1;
	else if (ft_strcmp(rule, "rrr") == 0)
		*re = 1;
}

int	check_rules(char *rule)
{
	int	re;

	re = -1;
	check_one(rule, &re);
	check_two(rule, &re);
	return (re);
}
