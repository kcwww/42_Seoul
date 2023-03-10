/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 19:40:22 by chanwoki          #+#    #+#             */
/*   Updated: 2023/03/10 20:37:40 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sorting_three(t_ps *a, t_ps *b, t_three *t)
{
	int		head;
	int		next;

	head = a->head->content;
	next = a->head->next->content;
	if (head == t->min)
	{
		execute_rules("pb", a, b);
		execute_rules("sa", a, b);
		execute_rules("pa", a, b);
	}
	else if (head == t->mid)
	{
		if (next == t->min)
			execute_rules("sa", a, b);
		else if (next == t->max)
			execute_rules("rra", a, b);
	}
	else if (head == t->max)
	{
		if (next == t->mid)
		{
			execute_rules("ra", a, b);
			execute_rules("sa", a, b);
		}
		else if (next == t->min)
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
