/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greeding.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 00:22:12 by chanwoki          #+#    #+#             */
/*   Updated: 2023/03/27 01:39:03 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	go_count_rules(t_num *num, t_deque *lst, int flag, t_ps *a)
{
	while (lst)
	{
		num->temp = counting_rules(a, lst->content, num->hi, flag);
		if (num->ti > num->temp)
			num->ti = num->temp;
		if (num->ti == 0)
			break ;
		if (flag == 1)
			num->hi--;
		else
			num->hi++;
		if (num->hi > (num->compare / 2))
		{
			flag = 1;
			if (num->compare % 2 == 1)
				num->hi--;
			else
				num->hi -= 2;
		}
		lst = lst->next;
	}
}

void	greeding(t_ps *a, t_ps *b)
{
	t_deque	*lst;
	t_num	num;
	int		flag;

	if (b->head == NULL)
		return ;
	lst = b->head;
	num.compare = ft_dequesize(b->head);
	num.hi = 0;
	flag = 0;
	num.ti = counting_rules(a, lst->content, num.hi, flag);
	num.hi++;
	lst = lst->next;
	go_count_rules(&num, lst, flag, a);
	choose_greed(a, b, num.ti);
}
