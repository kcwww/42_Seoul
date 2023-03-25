/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_greed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwookim <chanwookim@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:13:31 by chanwookim        #+#    #+#             */
/*   Updated: 2023/03/25 14:18:53 by chanwookim       ###   ########.fr       */
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
	
	lst = a->head;
	hi = 0;
	ti = ft_dequesize(a->head);
	temp = lst->content;
	compare = lst->next->content;
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

void    exe_pa(t_ps *a, t_ps *b)
{
	t_deque	*lst;
	int		pa_num;
	int		hnum;
	int		tnum;

	pa_num = b->head->content;
	hnum = a->head->content;
	tnum = a->tail->content;
	if (pa_num > hnum && pa_num > tnum)
	{

	}
	else if (pa_num > hnum && pa_num < tnum)
	{

	}
	else if (pa_num < hnum && pa_num > tnum)
	{

	}
	else if (pa_num < hnum && pa_num < tnum)
	{

	}
    execute_rules("pa", a, b);
}

void    choose_greed(t_ps *a, t_ps *b, int min)
{
    t_deque	*lst;
	int		count;
	int		i;
	int		size;
	int		flag;

	if (b->head == NULL)
		return ;
	lst = b->head;
	size = ft_dequesize(b->head);
	i = 0;
	flag = 0;
	while (lst)
	{
		count = counting_rules(a, lst->content, i);
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
    while (i)
    {
        if (flag == 1)
            execute_rules("rrb", a, b);
        else
            execute_rules("rb", a, b);
        i--;
    }
   exe_pa(a, b);
}