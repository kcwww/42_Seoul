/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_greed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:13:31 by chanwookim        #+#    #+#             */
/*   Updated: 2023/03/26 15:56:27 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	go_sorting(t_ps *a, t_ps *b)
{
	t_deque	*lst;
	int		temp;
	int 	compare;
	int		hi;
	int		ti;

	if (check_sorting(a) == 1)
		return ;
	//print_stack("go sorting", a, b);
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
	//print_stack("after sorting", a, b);
}

void	exe_remain(int ra, int rra, int rb, int rrb, t_ps *a, t_ps *b)
{
	while (ra > 0)
	{
		execute_rules("ra", a, b);
		ra--;
	}
	while (rra > 0)
	{
		execute_rules("rra", a, b);
		rra--;
	}
	while (rb > 0)
	{
		execute_rules("rb", a, b);
		rb--;
	}
	while (rrb > 0)
	{
		execute_rules("rrb", a, b);
		rrb--;
	}
}

void	exe_rr(int ra, int rra, int rb, int rrb, t_ps *a, t_ps *b)
{
	while (ra && rb)
	{
		execute_rules("rr", a, b);
		ra--;
		rb--;
	}
	while (rra && rrb)
	{
		execute_rules("rrr", a, b);
		rra--;
		rrb--;
	}
	exe_remain(ra, rra, rb, rrb, a, b);
}

void	exe_pa(t_ps *a, t_ps *b, int num, int rrb, int rb)
{
	t_deque	*lst;
	int		pa_num;
	int		hnum;
	int		tnum;
	int		rra = 0;
	int		ra = 0;

	pa_num = num;
	hnum = a->head->content;
	tnum = a->tail->content;

	int		hi;
	int		ti;
	int		temp;

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
		exe_rr(ra, rra, rb, rrb, a, b);
		execute_rules("pa", a, b);
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
		exe_rr(ra, rra, rb, rrb, a, b);
		execute_rules("pa", a, b);
	}
	else if (pa_num < hnum && pa_num > tnum)
	{
		exe_rr(ra, rra, rb, rrb, a, b);
		execute_rules("pa", a, b);
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
		else if (temp > ti)
			rra = ti;
		else
			ra = temp;
		exe_rr(ra, rra, rb, rrb, a, b);
		execute_rules("pa", a, b);
	}
}

void    choose_greed(t_ps *a, t_ps *b, int min)
{
    t_deque	*lst;
	int		count;
	int		i;
	int		size;
	int		flag;
	int		rrb = 0;
	int		rb = 0;

	if (b->head == NULL)
		return ;
	lst = b->head;
	size = ft_dequesize(b->head);
	i = 0;
	flag = 0;
	while (lst)
	{
		count = counting_rules(a, lst->content, i, flag);
		if (min == count)
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
	if (flag == 1)
		rrb = i;
	else
		rb = i;
	if (lst == NULL)
		lst = b->tail;
	exe_pa(a, b, lst->content, rrb, rb);
}
