/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rule_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwookim <chanwookim@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:44:49 by chanwoki          #+#    #+#             */
/*   Updated: 2023/03/30 12:43:17 by chanwookim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	exe_s(char *rule, t_num num, t_ps *a, t_ps *b)
{
	int	check_a;
	int	check_b;

	check_a = num.hi;
	check_b = num.ti;
	if (ft_strncmp(rule, "sa", 2) == 0)
		rule_sa(check_a, a);
	else if (ft_strncmp(rule, "sb", 2) == 0)
		rule_sb(check_b, b);
	else if (ft_strncmp(rule, "ss", 2) == 0)
	{
		rule_sa(check_a, a);
		rule_sb(check_b, b);
	}
}

static void	exe_push(char *rule, t_num num, t_ps *a, t_ps *b)
{
	int	check_a;
	int	check_b;

	check_a = num.hi;
	check_b = num.ti;
	if (ft_strncmp(rule, "pa", 2) == 0)
		rule_pa(check_b, a, b);
	else if (ft_strncmp(rule, "pb", 2) == 0)
		rule_pb(check_a, a, b);
}

static void	exe_re(char *rule, t_num num, t_ps *a, t_ps *b)
{
	int	check_a;
	int	check_b;

	check_a = num.hi;
	check_b = num.ti;
	if (ft_strncmp(rule, "ra", 2) == 0)
		rule_ra(check_a, a);
	else if (ft_strncmp(rule, "rb", 2) == 0)
		rule_rb(check_b, b);
	else if (ft_strncmp(rule, "rr", 2) == 0 && ft_strlen(rule) == 2)
	{
		rule_ra(check_a, a);
		rule_rb(check_b, b);
	}
}

static void	exe_rre(char *rule, t_num num, t_ps *a, t_ps *b)
{
	int	check_a;
	int	check_b;

	check_a = num.hi;
	check_b = num.ti;
	if (ft_strncmp(rule, "rra", 3) == 0)
		rule_rra(check_a, a);
	else if (ft_strncmp(rule, "rrb", 3) == 0)
		rule_rrb(check_b, b);
	else if (ft_strncmp(rule, "rrr", 3) == 0)
	{
		rule_rra(check_a, a);
		rule_rrb(check_b, b);
	}
}

void	execute_rules(char *rule, t_ps *a, t_ps *b)
{
	t_num	num;

	num.hi = check_lst(a);
	num.ti = check_lst(b);
	if (rule[0] == 's')
		exe_s(rule, num, a, b);
	else if (rule[0] == 'p')
		exe_push(rule, num, a, b);
	else if (rule[2] == '\0')
		exe_re(rule, num, a, b);
	else
		exe_rre(rule, num, a, b);
}
