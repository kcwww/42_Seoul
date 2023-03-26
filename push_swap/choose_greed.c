/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_greed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:13:31 by chanwookim        #+#    #+#             */
/*   Updated: 2023/03/27 02:38:29 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exe_remain(t_rules *rule, t_ps *a, t_ps *b)
{
	while (rule->ra > 0)
	{
		execute_rules("ra", a, b);
		rule->ra--;
	}
	while (rule->rra > 0)
	{
		execute_rules("rra", a, b);
		rule->rra--;
	}
	while (rule->rb > 0)
	{
		execute_rules("rb", a, b);
		rule->rb--;
	}
	while (rule->rrb > 0)
	{
		execute_rules("rrb", a, b);
		rule->rrb--;
	}
}

void	exe_rr(t_rules *rule, t_ps *a, t_ps *b)
{
	while (rule->ra && rule->rb)
	{
		execute_rules("rr", a, b);
		rule->ra--;
		rule->rb--;
	}
	while (rule->rra && rule->rrb)
	{
		execute_rules("rrr", a, b);
		rule->rra--;
		rule->rrb--;
	}
	exe_remain(rule, a, b);
}

static t_deque	*find_min_num(t_ps *a, t_ps *b, t_num *num, int min)
{
	t_deque	*lst;

	lst = b->head;
	while (lst)
	{
		num->temp = counting_rules(a, lst->content, num->hi, num->ti);
		if (min == num->temp)
			break ;
		if (num->ti == 1)
			num->hi--;
		else
			num->hi++;
		if (num->hi > (num->compare / 2))
		{
			num->ti = 1;
			if (num->compare % 2 == 1)
				num->hi--;
			else
				num->hi -= 2;
		}
		lst = lst->next;
	}
	return (lst);
}

void	choose_greed(t_ps *a, t_ps *b, int min)
{
	t_deque	*lst;
	t_rules	rule;
	t_num	num;

	ft_memset(&rule, 0, sizeof(t_rules));
	ft_memset(&num, 0, sizeof(t_num));
	if (b->head == NULL)
		return ;
	num.compare = ft_dequesize(b->head);
	lst = find_min_num(a, b, &num, min);
	if (num.ti == 1)
		rule.rrb = num.hi;
	else
		rule.rb = num.hi;
	exe_pa(a, b, lst->content, &rule);
}
