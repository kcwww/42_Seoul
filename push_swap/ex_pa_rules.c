/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_pa_rules.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 02:42:08 by chanwoki          #+#    #+#             */
/*   Updated: 2023/03/27 03:09:57 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	big_assist(t_num *num, t_ps *a, int pa_num)
{
	t_deque	*lst;

	lst = a->head;
	while (lst)
	{
		if (lst->content > pa_num)
			break ;
		num->hi++;
		lst = lst->next;
	}
	lst = a->tail;
	while (lst)
	{
		num->ti++;
		if (lst->content > pa_num)
		{
			num->temp = num->ti;
		}
		lst = lst->previous;
	}
}

void	ex_both_big(int pa_num, t_ps *a, t_ps *b, t_rules *rule)
{
	t_num	num;

	ft_memset(&num, 0, sizeof(t_num));
	big_assist(&num, a, pa_num);
	if (num.hi == ft_dequesize(a->head))
		count_sorting(a, &rule->ra, &rule->rra);
	else if (num.hi > num.temp)
		rule->rra = num.temp;
	else
		rule->ra = num.hi;
	exe_rr(rule, a, b);
	execute_rules("pa", a, b);
}

void	mid_assist(t_num *num, t_ps *a, int pa_num)
{
	t_deque	*lst;

	lst = a->head;
	while (lst)
	{
		if (lst->content > pa_num)
			break ;
		num->hi++;
		lst = lst->next;
	}
	lst = a->tail;
	while (lst)
	{
		if (lst->content < pa_num)
			break ;
		num->ti++;
		lst = lst->previous;
	}
}

static void	small_assist(t_num *num, t_ps *a, int pa_num)
{
	t_deque	*lst;

	lst = a->head;
	while (lst)
	{
		num->hi++;
		if (lst->content < pa_num)
			num->temp = num->hi;
		lst = lst->next;
	}
	lst = a->tail;
	while (lst)
	{
		if (lst->content < pa_num)
			break ;
		num->ti++;
		lst = lst->previous;
	}
}

void	ex_both_small(int pa_num, t_ps *a, t_ps *b, t_rules *rule)
{
	t_num	num;

	ft_memset(&num, 0, sizeof(t_num));
	small_assist(&num, a, pa_num);
	if (num.ti == ft_dequesize(a->head))
		count_sorting(a, &rule->ra, &rule->rra);
	else if (num.temp > num.ti)
		rule->rra = num.ti;
	else
		rule->ra = num.temp;
	exe_rr(rule, a, b);
	execute_rules("pa", a, b);
}
