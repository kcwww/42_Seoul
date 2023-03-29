/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwookim <chanwookim@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 01:01:44 by chanwoki          #+#    #+#             */
/*   Updated: 2023/03/30 02:25:54 by chanwookim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

static void	assist_push(t_ps *a, t_ps *b, t_deque *lst, int flag)
{
	if (flag == 0)
	{
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
		return ;
	}
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
}

int	rule_pa(int check_b, t_ps *a, t_ps *b)
{
	t_deque	*lst;
	t_deque	*temp;

	if (check_b == 0)
		return (0);
	lst = b->head;
	temp = b->head->next;
	assist_push(a, b, lst, 0);
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
	assist_push(a, b, lst, 1);
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
