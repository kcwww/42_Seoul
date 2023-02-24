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

	if (check_a == 0 || check_a == 1)
		return ;
	lst = A->head->next;
	temp = A->head;
	temp->next = lst->next;
	lst->next = temp;
	lst->previous = NULL;
	temp->previous = lst;
	A->head = lst;
	if (check_a == 2)
	{
		A->tail = A->head->next;
		return ;
	}
	temp = temp->next;
	temp->previous = lst->next;
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
	lst->next = temp;
	lst->previous = NULL;
	temp->previous = lst;
	B->head = lst;
	if (check_b == 2)
	{
		B->tail = B->head->next;
		return ;
	}
	temp = temp->next;
	temp->previous = lst->next;
}

void	rule_pa(int check_b, t_ps *A, t_ps *B)
{
	t_deque	*lst;
	t_deque	*temp;

	if (check_b == 0)
		return ;
	lst = B->head;
	temp = B->head->next;
	if (A->head != NULL)
	{
		lst->next = A->head;
		A->head->previous = lst;
	}
	else
	{
		A->tail = lst;
		lst->next = NULL;
	}
	lst->previous = NULL;
	A->head = lst;
	if (check_b == 1)
	{
		B->head = NULL;
		return ;
	}
	B->head = temp;
	temp->previous = NULL;
}

void	rule_pb(int check_a, t_ps *A, t_ps *B)
{
	t_deque	*lst;
	t_deque	*temp;

	if (check_a == 0)
		return ;
	lst = A->head;
	temp = A->head->next;
	if (B->head != NULL)
	{
		lst->next = B->head;
		B->head->previous = lst;
	}
	else
	{
		B->tail = lst;
		lst->next = NULL;
	}
	lst->previous = NULL;
	B->head = lst;
	if (check_a == 1)
	{
		A->head = NULL;
		return ;
	}
	A->head = temp;
	temp->previous = NULL;
}

void	execute_rules(char	*rule, t_ps *A, t_ps *B)
{
	int	check_a;
	int	check_b;

	check_a = check_lst(A);
	check_b = check_lst(B);

	//ft_printf("a is %d b is %d\n",check_a,check_b);
	
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
