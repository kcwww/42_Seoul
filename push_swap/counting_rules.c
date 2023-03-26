/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counting_rules.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 01:23:57 by chanwoki          #+#    #+#             */
/*   Updated: 2023/03/27 02:10:08 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	count_reverse(t_rules *rule)
{
	if (rule->rra > 0 && rule->rrb > 0)
	{
		if (rule->rra >= rule->rrb)
			rule->rra = rule->rra - rule->rrb;
		else
			rule->rrb = rule->rrb - rule->rra;
	}
	else if (rule->ra > 0 && rule->rb > 0)
	{
		if (rule->ra >= rule->rb)
			rule->ra = rule->ra - rule->rb;
		else
			rule->rb = rule->rb - rule->ra;
	}
}

int	counting_rules(t_ps *a, int num, int idx, int flag)
{
	t_rules	rule;
	int		pa_num;
	int		hnum;
	int		tnum;

	pa_num = num;
	hnum = a->head->content;
	tnum = a->tail->content;
	ft_memset(&rule, 0, sizeof(t_rules));
	if (flag == 1)
		rule.rrb = idx;
	else
		rule.rb = idx;
	if (pa_num > hnum && pa_num > tnum)
		both_big(pa_num, a, &rule, a->head);
	else if (pa_num > hnum && pa_num < tnum)
		big_and_small(pa_num, a, &rule);
	else if (pa_num < hnum && pa_num < tnum)
		both_small(pa_num, a, &rule, a->head);
	count_reverse(&rule);
	return (rule.rra + rule.ra + rule.rb + rule.rrb);
}
