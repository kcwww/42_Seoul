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

void	rule_sa(int check_a, t_ps *A)
{
	t_deque	*lst;
	t_deque	*temp;

	if (check_a == 0)
		return ;
	lst = A->head->next;
	temp = A->head;
	temp->next = lst->next;
	temp->next->previous = temp;
	temp->previous = lst;
	lst->next = temp;
	lst->previous = NULL;
	A->head = A->head->next;
	if (check_a == 1)
		A->tail = A->head->next;
}

void	rule_sb(int check_b, t_ps *B)
{
	t_deque	*lst;
	t_deque	*temp;

	if (check_b == 0 || check_b == 1)
		return ;
	lst = B->head->next;
	temp = B->head;
	temp->next = lst->next;
	temp->next->previous = temp;
	temp->previous = lst;
	lst->next = temp;
	lst->previous = NULL;
	B->head = B->head->next;
	if (check_b == 2)
		B->tail = B->head->next;
}

void	rule_pa(int check_b, t_ps *A, t_ps *B)
{
	t_deque	*lst;
	t_deque	*temp;

	if (check_b == 0)
		return ;
	lst = B->head;
	lst->next = A->head;
	lst->previous = NULL;
	A->head->previous = lst;
	A->head = lst;
	B->head = B->head->next;
	B->head->previous = NULL;
}

void	rule_pb(int check_a, t_ps *A, t_ps *B)
{
	t_deque	*lst;
	t_deque	*temp;

	if (check_a == 0)
		return ;
	lst = A->head;
	lst->next = B->head;
	lst->previous = NULL;
	if (B->head != NULL)
		B->head->previous = lst;
	B->head = lst;
	A->head = A->head->next;
	A->head->previous = NULL;
}

void	execute_rules(char	*rule, t_ps *A, t_ps *B)
{
	int	check_a;
	int	check_b;

	if (ft_strncmp(rule, "sa", 2) == 0)
		rule_sa(check_a, A);
	else if (ft_strncmp(rule, "sb", 2) == 0)
		rule_sb(check_b, B);
	else if (ft_strncmp(rule, "ss", 2) == 0)
	{
		rule_sa(check_a, A);
		rule_sb(check_b, B);
	}
	else if (ft_strncmp(rule, "pa", 2) == 0)
		rule_pa(check_b, A, B);
	else if (ft_strncmp(rule, "pb", 2) == 0)
		rule_pb(check_a, A, B);
	else if (ft_strncmp(rule, "ra", 2) == 0)
		rule_ra(check_a, A);
	else if (ft_strncmp(rule, "rb", 2) == 0)
		rule_rb(check_b, B);
	else if (ft_strncmp(rule, "rr", 2) == 0 && ft_strlen(rule) == 2)
	{
		rule_ra(check_a, A);
		rule_rb(check_b, B);
	}
	else if (ft_strncmp(rule, "rra", 3) == 0)
		rule_rra(check_a, A);
	else if (ft_strncmp(rule, "rrb", 3) == 0)
		rule_rrb(check_b, B);
	else if (ft_strncmp(rule, "rrr", 3) == 0)
	{
		rule_rra(check_a, A);
		rule_rrb(check_b, B);
	}
}
