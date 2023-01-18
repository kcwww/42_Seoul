/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rule1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Cruleated: 2023/01/18 16:14:25 by chanwoki          #+#    #+#             */
/*   Updated: 2023/01/18 16:17:01 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rule_sa(int check_a, t_list **stack_a)
{
	t_list	*temp;

	if (check_a == 1 || check_a == 0)
		return ;
	temp = (*stack_a)->next;
	(*stack_a)->next = temp->next;
	temp->next = (*stack_a);
	(*stack_a) = temp;
}

void	rule_sb(int check_b, t_list **stack_b)
{
	t_list	*temp;

	if (check_b == 1 || check_b == 0)
		return ;
	temp = (*stack_b)->next;
	(*stack_b)->next = temp->next;
	temp->next = (*stack_b);
	(*stack_b) = temp;
}

void	rule_pa(int check_b, t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (check_b == 0)
		return ;
	temp = *stack_b;
	(*stack_b) = (*stack_b)->next;
	temp->next = (*stack_a);
	(*stack_a) = temp;
}

void	rule_pb(int check_a, t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if (check_a == 0)
		return ;
	temp = ft_lstnew((*stack_a)->content);
	temp->next = (*stack_b);
	(*stack_b) = temp;
	temp = (*stack_a)->next;
	free(*stack_a);
	(*stack_a) = temp;
}

void	execute_rules(char	*rule, t_list **stack_a, t_list **stack_b)
{
	int	check_a;
	int	check_b;

	check_a = check_lst(*stack_a);
	check_b = check_lst(*stack_b);
	if (ft_strncmp(rule, "sa", 2) == 0)
		rule_sa(check_a, stack_a);
	else if (ft_strncmp(rule, "sb", 2) == 0)
		rule_sb(check_b, stack_b);
	else if (ft_strncmp(rule, "ss", 2) == 0)
	{
		rule_sa(check_a, stack_a);
		rule_sb(check_b, stack_b);
	}
	else if (ft_strncmp(rule, "pa", 2) == 0)
		rule_pa(check_b, stack_a, stack_b);
	else if (ft_strncmp(rule, "pb", 2) == 0)
		rule_pb(check_a, stack_a, stack_b);
	else if (ft_strncmp(rule, "ra", 2) == 0)
		rule_ra(check_a, stack_a);
	else if (ft_strncmp(rule, "rb", 2) == 0)
		rule_rb(check_b, stack_b);
	else if (ft_strncmp(rule, "rr", 2) == 0 && ft_strlen(rule) == 2)
	{
		rule_ra(check_a, stack_a);
		rule_rb(check_b, stack_b);
	}
	else if (ft_strncmp(rule, "rra", 3) == 0)
		rule_rra(check_a, stack_a);
	else if (ft_strncmp(rule, "rrb", 3) == 0)
		rule_rrb(check_b, stack_b);
	else if (ft_strncmp(rule, "rrr", 3) == 0)
	{
		rule_rra(check_a, stack_a);
		rule_rrb(check_b, stack_b);
	}
}
