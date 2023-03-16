/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rule2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:26:16 by chanwoki          #+#    #+#             */
/*   Updated: 2023/03/16 23:32:13 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rule_ra(int check_a, t_ps *A)
{
	t_deque	*lst;
	t_deque	*temp;

	if (check_a == 1 || check_a == 0)
		return (0);
	if (check_a == 2)
	{
		rule_sa(check_a, A);
		return (1);
	}
	lst = A->head;
	temp = A->head->next;
	lst->previous = A->tail;
	lst->previous->next = lst;
	lst->next = NULL;
	A->tail = lst;
	A->head = temp;
	A->head->previous = NULL;
	return (1);
}

int	rule_rb(int check_b, t_ps *B)
{
	t_deque	*lst;
	t_deque	*temp;

	if (check_b == 1 || check_b == 0)
		return (0);
	if (check_b == 2)
	{
		rule_sb(check_b, B);
		return (1);
	}
	lst = B->head;
	temp = B->head->next;
	lst->previous = B->tail;
	lst->previous->next = lst;
	lst->next = NULL;
	B->tail = lst;
	B->head = temp;
	B->head->previous = NULL;
	return (1);
}

int	rule_rra(int check_a, t_ps *A)
{
	t_deque	*lst;
	t_deque	*temp;

	if (check_a == 1 || check_a == 0)
		return (0);
	if (check_a == 2)
	{
		rule_sa(check_a, A);
		return (1);
	}
	temp = A->tail->previous;
	lst = A->tail;
	lst->next = A->head;
	lst->previous = NULL;
	A->head = lst;
	A->tail = temp;
	A->tail->next = NULL;
	temp = A->head->next;
	temp->previous = A->head;
	return (1);
}

int	rule_rrb(int check_b, t_ps *B)
{
	t_deque	*lst;
	t_deque	*temp;

	if (check_b == 1 || check_b == 0)
		return (0);
	if (check_b == 2)
	{
		rule_sb(check_b, B);
		return (1);
	}
	temp = B->tail->previous;
	lst = B->tail;
	lst->next = B->head;
	lst->previous = NULL;
	B->head = lst;
	B->tail = temp;
	B->tail->next = NULL;
	temp = B->head->next;
	temp->previous = B->head;
	return (1);
}
