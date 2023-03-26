/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greeding.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 00:22:12 by chanwoki          #+#    #+#             */
/*   Updated: 2023/03/26 15:56:15 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	count_sorting(t_ps *a, int *ra, int *rra)
{
	t_deque	*lst;
	int		temp;
	int 	compare;
	int		hi;
	int		ti;

	if (check_sorting(a) == 1)
		return ;
	lst = a->head;
	hi = 0;
	ti = ft_dequesize(a->head);
	while (lst->next)
	{
		temp = lst->content;
		compare = lst->next->content;
		hi++;
		if (temp > compare)
			break ;
		lst = lst->next;
	}
	if (hi > (ti / 2))
		(*rra) = ft_dequesize(a->head) - hi;
	else
		(*ra) = hi;
}

int	counting_rules(t_ps *a, int num, int idx, int flag)
{
	t_deque	*lst;
	int		pa_num;
	int		hnum;
	int		tnum;
	int		rra = 0;
	int		ra = 0;
	int		rrb = 0;
	int		rb = 0;

	pa_num = num;
	hnum = a->head->content;
	tnum = a->tail->content;

	int		hi;
	int		ti;
	int		temp;

	if (flag == 1)
		rrb = idx;
	else
		rb = idx;

	if (pa_num > hnum && pa_num > tnum)
	{
		hi = 0;
		ti = 0;
		temp = 0;
		lst = a->head;
		while (lst)
		{
			if (lst->content > pa_num)
				break ;
			hi++;
			lst = lst->next;
		}
		lst = a->tail;
		while (lst)
		{
			ti++;
			if (lst->content > pa_num)
			{
				temp = ti;
			}
			lst = lst->previous;
		}
		if (hi == ft_dequesize(a->head))
			count_sorting(a, &ra, &rra);
		else if (hi > temp)
			rra = temp;
		else
			ra = hi;
	}
	else if (pa_num > hnum && pa_num < tnum)
	{
		lst = a->head;
		hi = 0;
		ti = 0;
		while (lst)
		{
			if (lst->content > pa_num)
				break ;
			hi++;
			lst = lst->next;
		}
		lst = a->tail;
		while (lst)
		{
			if (lst->content < pa_num)
				break ;
			ti++;
			lst = lst->previous;
		}
		if (hi > ti)
			rra = ti;
		else
			ra = hi;
	}
	else if (pa_num < hnum && pa_num < tnum)
	{
		hi = 0;
		ti = 0;
		temp = 0;
		lst = a->head;
		while (lst)
		{
			hi++;
			if (lst->content < pa_num)
				temp = hi;
			lst = lst->next;
		}
		lst = a->tail;
		while (lst)
		{
			if (lst->content < pa_num)
				break ;
			ti++;
			lst = lst->previous;
		}
		if (ti == ft_dequesize(a->head))
			count_sorting(a, &ra, &rra);
		else if (hi > ti)
			rra = ti;
		else
			ra = hi;
	}
	if (rra > 0 && rrb > 0)
	{
		if (rra >= rrb)
			rra = rra - rrb;
		else
			rrb = rrb - rra;
	}
	else if (ra > 0 && rb > 0)
	{
		if (ra >= rb)
			ra = ra - rb;
		else
			rb = rb - ra;
	}
	return (rra + ra + rb + rrb);
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
	size = ft_dequesize(b->head);
	i = 0;
	flag = 0;
	min = counting_rules(a, lst->content, i, flag);
	i++;
	lst = lst->next;
	while (lst)
	{
		count = counting_rules(a, lst->content, i, flag);
		if (min > count)
			min = count;
		if (min == 0)
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
}
