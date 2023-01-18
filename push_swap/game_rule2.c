/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_rule2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:26:16 by chanwoki          #+#    #+#             */
/*   Updated: 2023/01/18 17:43:09 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rule_ra(int check_a, t_list **stack_a)
{
	t_list	*list;
	t_list	*temp;

	if (check_a == 0 || check_a == 1)
		return ;
	list = ft_lstlast(*stack_a);
	temp = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	list->next = temp;
	temp->next = NULL;
}

void	rule_rb(int check_b, t_list **stack_b)
{
	t_list	*list;
	t_list	*temp;

	if (check_b == 0 || check_b == 1)
		return ;
	list = ft_lstlast(*stack_b);
	temp = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	list->next = temp;
	temp->next = NULL;
}

void	rule_rra(int check_a, t_list **stack_a)
{
	t_list	*list;
	t_list	*temp;

	if (check_a == 0 || check_a == 1)
		return ;
	list = ft_lstlastbefore(*stack_a);
	temp = list->next;
	list->next = NULL;
	temp->next = (*stack_a);
	(*stack_a) = temp;
}

void	rule_rrb(int check_b, t_list **stack_b)
{
	t_list	*list;
	t_list	*temp;

	if (check_b == 0 || check_b == 1)
		return ;
	list = ft_lstlastbefore(*stack_b);
	temp = list->next;
	list->next = NULL;
	temp->next = (*stack_b);
	(*stack_b) = temp;
}
