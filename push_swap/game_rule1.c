/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rule1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:44:49 by chanwoki          #+#    #+#             */
/*   Updated: 2023/03/26 15:14:09 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rule_sa(int check_a, t_ps *a)
{
	t_deque	*lst;
	t_deque	*temp;

	if (check_a == 0 || check_a == 1)
		return (0);
	lst = a->head->next;
	temp = a->head;
	temp->next = lst->next;
	lst->next = temp;
	lst->previous = NULL;
	temp->previous = lst;
	a->head = lst;
	if (check_a == 2)
	{
		a->tail = a->head->next;
		return (1);
	}
	temp = temp->next;
	temp->previous = lst->next;
	return (1);
}

int	rule_sb(int check_b, t_ps *b)
{
	t_deque	*lst;
	t_deque	*temp;

	if (check_b == 0 || check_b == 1)
		return (0);
	lst = b->head->next;
	temp = b->head;
	temp->next = lst->next;
	lst->next = temp;
	lst->previous = NULL;
	temp->previous = lst;
	b->head = lst;
	if (check_b == 2)
	{
		b->tail = b->head->next;
		return (1);
	}
	temp = temp->next;
	temp->previous = lst->next;
	return (1);
}

int	rule_pa(int check_b, t_ps *a, t_ps *b)
{
	t_deque	*lst;
	t_deque	*temp;

	if (check_b == 0)
		return (0);
	lst = b->head;
	temp = b->head->next;
	if (a->head != NULL)
	{
		lst->next = a->head;
		a->head->previous = lst;
	}
	else
	{
		a->tail = lst;
		lst->next = NULL;
	}
	lst->previous = NULL;
	a->head = lst;
	if (check_b == 1)
	{
		b->head = NULL;
		return (1);
	}
	b->head = temp;
	temp->previous = NULL;
	return (1);
}

int	rule_pb(int check_a, t_ps *a, t_ps *b)
{
	t_deque	*lst;
	t_deque	*temp;

	if (check_a == 0)
		return (0);
	lst = a->head;
	temp = a->head->next;
	if (b->head != NULL)
	{
		lst->next = b->head;
		b->head->previous = lst;
	}
	else
	{
		b->tail = lst;
		lst->next = NULL;
	}
	lst->previous = NULL;
	b->head = lst;
	if (check_a == 1)
	{
		a->head = NULL;
		return (1);
	}
	a->head = temp;
	temp->previous = NULL;
	return (1);
}

void	execute_rules(char	*rule, t_ps *a, t_ps *b)
{
	int	check_a;
	int	check_b;

	check_a = check_lst(a);
	check_b = check_lst(b);
	if (ft_strncmp(rule, "sa", 2) == 0)
	{
		if (rule_sa(check_a, a))
			ft_printf("sa\n");
	}
	else if (ft_strncmp(rule, "sb", 2) == 0)
	{
		if (rule_sb(check_b, b))
			ft_printf("sb\n");
	}
	else if (ft_strncmp(rule, "ss", 2) == 0)
	{
		if (rule_sa(check_a, a) || rule_sb(check_b, b))
			ft_printf("ss\n");
	}
	else if (ft_strncmp(rule, "pa", 2) == 0)
	{
		if (rule_pa(check_b, a, b))
			ft_printf("pa\n");
	}
	else if (ft_strncmp(rule, "pb", 2) == 0)
	{
		if (rule_pb(check_a, a, b))
			ft_printf("pb\n");
	}
	else if (ft_strncmp(rule, "ra", 2) == 0)
	{
		if (rule_ra(check_a, a))
			ft_printf("ra\n");
	}
	else if (ft_strncmp(rule, "rb", 2) == 0)
	{
		if (rule_rb(check_b, b))
			ft_printf("rb\n");
	}
	else if (ft_strncmp(rule, "rr", 2) == 0 && ft_strlen(rule) == 2)
	{
		if (rule_ra(check_a, a) && rule_rb(check_b, b))
			ft_printf("rr\n");
	}
	else if (ft_strncmp(rule, "rra", 3) == 0)
	{
		if (rule_rra(check_a, a))
			ft_printf("rra\n");
	}
	else if (ft_strncmp(rule, "rrb", 3) == 0)
	{
		if (rule_rrb(check_b, b))
			ft_printf("rrb\n");
	}
	else if (ft_strncmp(rule, "rrr", 3) == 0)
	{
		if (rule_rra(check_a, a) && rule_rrb(check_b, b))
			ft_printf("rrr\n");
	}
}
