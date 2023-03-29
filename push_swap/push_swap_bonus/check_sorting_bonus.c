/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwookim <chanwookim@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:35:44 by chanwoki          #+#    #+#             */
/*   Updated: 2023/03/30 01:52:58 by chanwookim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_sorting_bonus(t_ps *a, t_ps *b)
{
	t_deque	*lst;
	int		temp;
	int		compare;

	if (b->head != NULL)
		return (0);
	lst = a->head;
	temp = lst->content;
	lst = lst->next;
	while (lst)
	{
		compare = lst->content;
		lst = lst->next;
		if (temp > compare)
			return (0);
		temp = compare;
	}
	return (1);
}
