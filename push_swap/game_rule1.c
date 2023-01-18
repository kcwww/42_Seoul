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

void	execute_rules(char	*rule, t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	t_list	*list;
	int		check_a, check_b;

	check_a = check_lst(*stack_a);
	check_b = check_lst(*stack_b);

	if (ft_strncmp(rule, "sa", 2) == 0)
	{
		if (check_a != 0 && check_a != 1)
		{
			temp = (*stack_a)->next;
			(*stack_a)->next = temp->next;
			temp->next = (*stack_a);
			(*stack_a) = temp;
		}
	}

	else if (ft_strncmp(rule, "sb", 2) == 0)
	{
		if (check_b != 0 && check_b != 1)
		{
			temp = (*stack_b)->next;
			(*stack_b)->next = temp->next;
			temp->next = (*stack_b);
			(*stack_b) = temp;
		}
	}

	// else if (ft_strcmp(rule, "ss") == 0)
	// {

	// }

	else if (ft_strncmp(rule, "pa", 2) == 0)
	{
		if (check_b != 0)
		{
			temp = *stack_b;
			(*stack_b) = (*stack_b)->next;
			temp->next = (*stack_a);
			(*stack_a) = temp;
		}
	}

	else if (ft_strncmp(rule, "pb", 2) == 0)
	{
		if (check_a != 0)
		{
			temp = ft_lstnew((*stack_a)->content);
			temp->next = (*stack_b);
			(*stack_b) = temp;
			temp = (*stack_a)->next;
			free(*stack_a);
			(*stack_a) = temp;
		}
	}

	else if (ft_strncmp(rule, "ra", 2) == 0)
	{
		if (check_a != 0 && check_a != 1)
		{
			list = ft_lstlast(*stack_a);
			temp = (*stack_a);
			(*stack_a) = (*stack_a)->next;
			list->next = temp;
			temp->next = NULL;
		}
	}

	else if (ft_strncmp(rule, "rb", 2) == 0)
	{
		if (check_b != 0 && check_b != 1)
		{
			list = ft_lstlast(*stack_b);
			temp = (*stack_b);
			(*stack_b) = (*stack_b)->next;
			list->next = temp;
			temp->next = NULL;
		}
	}

	// else if (ft_strcmp(rule, "rr") == 0)
	// {

	// }

	else if (ft_strncmp(rule, "rra", 3) == 0)
	{
		if (check_a != 0 && check_a != 1)
		{
			list = ft_lstlastbefore(*stack_a);
			temp = list->next;
			list->next = NULL;
			temp->next = (*stack_a);
			(*stack_a) = temp;
		}
	}

	else if (ft_strncmp(rule, "rrb", 3) == 0)
	{
		if (check_b != 0 && check_b != 1)
		{
			list = ft_lstlastbefore(*stack_b);
			temp = list->next;
			list->next = NULL;
			temp->next = (*stack_b);
			(*stack_b) = temp;
		}
	}

	// else if (ft_strcmp(rule, "rrr") == 0)
	// {

	// }
}
