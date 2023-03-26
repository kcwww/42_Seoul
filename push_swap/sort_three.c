/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 19:40:22 by chanwoki          #+#    #+#             */
/*   Updated: 2023/03/27 00:30:08 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sorting_three(t_ps *a, t_ps *b, t_three *t)
{
	if (a->head->content == t->min)
	{
		execute_rules("pb", a, b);
		execute_rules("sa", a, b);
		execute_rules("pa", a, b);
	}
	else if (a->head->content == t->mid)
	{
		if (a->head->next->content == t->min)
			execute_rules("sa", a, b);
		else if (a->head->next->content == t->max)
			execute_rules("rra", a, b);
	}
	else if (a->head->content == t->max)
	{
		if (a->head->next->content == t->mid)
		{
			execute_rules("ra", a, b);
			execute_rules("sa", a, b);
		}
		else if (a->head->next->content == t->min)
			execute_rules("ra", a, b);
	}
}

void	sort_three(t_ps *a, t_ps *b)
{
	t_three	t;
	t_deque	*lst;

	lst = a->head;
	t.min = lst->content;
	t.max = t.min;
	if (check_sorting(a) == 1)
		return ;
	while (lst)
	{
		if (t.min > lst->content)
			t.min = lst->content;
		else if (t.max < lst->content)
			t.max = lst->content;
		lst = lst->next;
	}
	lst = a->head;
	while (lst)
	{
		if (lst->content != t.max && lst->content != t.min)
			t.mid = lst->content;
		lst = lst->next;
	}
	sorting_three(a, b, &t);
}
