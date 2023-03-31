/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:24:56 by chanwoki          #+#    #+#             */
/*   Updated: 2023/03/31 16:49:31 by chanwoki         ###   ########.fr       */
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

static void	list_to_arr(t_ps *a, int *arr)
{
	t_deque	*lst;
	int		i;

	lst = a->head;
	i = 0;
	while (lst)
	{
		arr[i] = lst->content;
		lst = lst->next;
		i++;
	}
}

static int	setting_pivot(t_ps *a, int *pia, int *pib)
{
	int	len;
	int	idx;
	int	*arr;

	len = ft_dequesize(a->head);
	idx = 0;
	arr = (int *)malloc(sizeof(int) * len);
	if (arr == NULL)
		return (0);
	list_to_arr(a, arr);
	select_sort(arr, len);
	*pia = arr[len / 3];
	*pib = arr[(len / 3) * 2];
	free(arr);
	return (1);
}

int	set_pivot(t_ps *a, t_ps *b)
{
	int		pivot_a;
	int		pivot_b;

	if (a->head->next == NULL)
		return (0);
	pivot_a = 0;
	pivot_b = 0;
	if (setting_pivot(a, &pivot_a, &pivot_b) == 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	partitioning(a, b, pivot_a, pivot_b);
	while (b->head)
		greeding(a, b);
	go_sorting(a, b);
	return (1);
}
