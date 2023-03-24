/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greeding.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwookim <chanwookim@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 00:22:12 by chanwoki          #+#    #+#             */
/*   Updated: 2023/03/24 13:56:41 by chanwookim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	counting_rules(t_ps *a, int num, int idx)
{
	t_deque	*lst;
	int		re;
	int		hi;
	int		ti;

	re = 1;
	hi = 0;
	ti = 1;
	lst = a->head;
	while (lst)
	{
		if (lst->content > num)
			break ;
		lst = lst->next;
		hi++;
	}
	lst = a->tail;
	while (lst)
	{
		if (lst->content > num)
			break ;
		lst = lst->previous;
		ti++;
	}
	if (hi > ti)
		hi = ti;
	if (hi == ft_dequesize(a->head))
		hi = 0;
	ft_printf("\n\n hi is %d\n\n", hi);
	return (re + hi + idx);
}

void	greeding(t_ps *a, t_ps *b)
{
	t_deque	*lst;
	int		count;
	int		min;
	int		i;
	int		size;
	int		flag;

	if (b->head == NULL)
		return ;
	lst = b->head;
	min = ft_dequesize(b->head);
	size = min;
	i = 0;
	flag = 0;
	while (lst)
	{
		count = counting_rules(a, lst->content, i);
		if (min > count)
			min = count;
		if (min == 1)
			break ;
		if (flag == 1)
			i--;
		else
			i++;
		if (i > (size / 2))
		{
			flag = 1;
			if (size % 2 == 1)
				i--;
			else
				i -= 2;
		}
		lst = lst->next;
	}
	choose_greed(a, b, min);
	ft_printf("\n\n min is %d\n\n", min);
}
