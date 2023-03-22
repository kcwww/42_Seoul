/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwookim <chanwookim@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:35:44 by chanwoki          #+#    #+#             */
/*   Updated: 2023/03/22 16:42:09 by chanwookim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorting(t_ps *a)
{
	t_deque	*lst;
	int		temp;
	int		compare;

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
