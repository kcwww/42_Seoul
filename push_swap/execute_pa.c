/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 02:13:44 by chanwoki          #+#    #+#             */
/*   Updated: 2023/03/27 03:07:39 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ex_big_and_small(int pa_num, t_ps *a, t_ps *b, t_rules *rule)
{
	t_num	num;

	ft_memset(&num, 0, sizeof(t_num));
	mid_assist(&num, a, pa_num);
	if (num.hi > num.ti)
		rule->rra = num.ti;
	else
		rule->ra = num.hi;
	exe_rr(rule, a, b);
	execute_rules("pa", a, b);
}

void	exe_pa(t_ps *a, t_ps *b, int num, t_rules *rule)
{
	int		hnum;
	int		tnum;

	hnum = a->head->content;
	tnum = a->tail->content;
	if (num > hnum && num > tnum)
		ex_both_big(num, a, b, rule);
	else if (num > hnum && num < tnum)
		ex_big_and_small(num, a, b, rule);
	else if (num < hnum && num > tnum)
	{
		exe_rr(rule, a, b);
		execute_rules("pa", a, b);
	}
	else if (num < hnum && num < tnum)
		ex_both_small(num, a, b, rule);
}
