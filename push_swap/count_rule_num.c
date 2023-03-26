/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_rule_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 01:49:30 by chanwoki          #+#    #+#             */
/*   Updated: 2023/03/27 02:09:57 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	both_big(int pa_num, t_ps *a, t_rules *rule, t_deque *lst)
{
	t_num	num;

	ft_memset(&num, 0, sizeof(t_num));
	while (lst)
	{
		if (lst->content > pa_num)
			break ;
		num.hi++;
		lst = lst->next;
	}
	lst = a->tail;
	while (lst)
	{
		num.ti++;
		if (lst->content > pa_num)
			num.temp = num.ti;
		lst = lst->previous;
	}
	if (num.hi == ft_dequesize(a->head))
		count_sorting(a, &rule->ra, &rule->rra);
	else if (num.hi > num.temp)
		rule->rra = num.temp;
	else
		rule->ra = num.hi;
}

void	big_and_small(int pa_num, t_ps *a, t_rules *rule)
{
	t_deque	*lst;
	t_num	num;

	lst = a->head;
	ft_memset(&num, 0, sizeof(t_num));
	while (lst)
	{
		if (lst->content > pa_num)
			break ;
		num.hi++;
		lst = lst->next;
	}
	lst = a->tail;
	while (lst)
	{
		if (lst->content < pa_num)
			break ;
		num.ti++;
		lst = lst->previous;
	}
	if (num.hi > num.ti)
		rule->rra = num.ti;
	else
		rule->ra = num.hi;
}

void	both_small(int pa_num, t_ps *a, t_rules *rule, t_deque *lst)
{
	t_num	num;

	ft_memset(&num, 0, sizeof(t_num));
	while (lst)
	{
		num.hi++;
		if (lst->content < pa_num)
			num.temp = num.hi;
		lst = lst->next;
	}
	lst = a->tail;
	while (lst)
	{
		if (lst->content < pa_num)
			break ;
		num.ti++;
		lst = lst->previous;
	}
	if (num.ti == ft_dequesize(a->head))
		count_sorting(a, &rule->ra, &rule->rra);
	else if (num.hi > num.ti)
		rule->rra = num.ti;
	else
		rule->ra = num.hi;
}
