/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:24:56 by chanwoki          #+#    #+#             */
/*   Updated: 2023/03/27 01:18:20 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	remaining_three(t_ps *a, t_ps *b)
{
	int	size;

	size = ft_dequesize(a->head);
	while (size > 3)
	{
		execute_rules("pb", a, b);
		size--;
	}
	sort_three(a, b);
}

void	partitioning(t_ps *a, t_ps *b, int pivot_a, int pivot_b)
{
	t_deque	*lst;
	t_deque	*temp;
	int		size;

	lst = a->head;
	size = ft_dequesize(lst);
	while (size)
	{
		if (ft_dequesize(a->head) == 3)
			break ;
		temp = lst;
		lst = lst->next;
		if (temp->content <= pivot_a)
		{
			execute_rules("pb", a, b);
			execute_rules("rb", a, b);
		}
		else if (temp->content > pivot_a && temp->content <= pivot_b)
			execute_rules("pb", a, b);
		else
			execute_rules("ra", a, b);
		size--;
	}
	remaining_three(a, b);
}

void	set_pivot(t_ps *a, t_ps *b)
{
	int		pivot_a;
	int		pivot_b;
	int		swap;

	if (a->head->next == NULL)
		return ;
	pivot_a = a->head->content;
	pivot_b = a->tail->content;
	if (pivot_a > pivot_b)
	{
		swap = pivot_a;
		pivot_a = pivot_b;
		pivot_b = swap;
	}
	partitioning(a, b, pivot_a, pivot_b);
	while (b->head)
		greeding(a, b);
	go_sorting(a, b);
}
