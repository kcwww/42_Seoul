/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:35:44 by chanwoki          #+#    #+#             */
/*   Updated: 2023/03/27 01:26:26 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	count_sorting(t_ps *a, int *ra, int *rra)
{
	t_deque	*lst;
	t_num	num;

	if (check_sorting(a) == 1)
		return ;
	lst = a->head;
	num.hi = 0;
	num.ti = ft_dequesize(a->head);
	while (lst->next)
	{
		num.temp = lst->content;
		num.compare = lst->next->content;
		num.hi++;
		if (num.temp > num.compare)
			break ;
		lst = lst->next;
	}
	if (num.hi > (num.ti / 2))
		(*rra) = ft_dequesize(a->head) - num.hi;
	else
		(*ra) = num.hi;
}

int	check_sorting(t_ps *a)
{
	t_deque	*lst;
	int		temp;
	int		compare;

	lst = a->head;
	temp = lst->content;
	lst = lst->next;
	while (lst)
	{
		compare = lst->content;
		lst = lst->next;
		if (temp > compare)
			return (0);
		temp = compare;
	}
	return (1);
}

static void	sort_re(t_ps *a, t_ps *b, int hi, int ti)
{
	if (hi > (ti / 2))
	{
		hi = ft_dequesize(a->head) - hi;
		while (hi)
		{
			execute_rules("rra", a, b);
			hi--;
		}
	}
	else
	{
		while (hi)
		{
			execute_rules("ra", a, b);
			hi--;
		}
	}
}

void	go_sorting(t_ps *a, t_ps *b)
{
	t_deque	*lst;
	t_num	num;

	if (check_sorting(a) == 1)
		return ;
	lst = a->head;
	num.hi = 0;
	num.ti = ft_dequesize(a->head);
	while (lst->next)
	{
		num.temp = lst->content;
		num.compare = lst->next->content;
		num.hi++;
		if (num.temp > num.compare)
			break ;
		lst = lst->next;
	}
	sort_re(a, b, num.hi, num.ti);
}
