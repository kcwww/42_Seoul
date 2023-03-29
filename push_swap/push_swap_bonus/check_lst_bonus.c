/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lst_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwookim <chanwookim@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:24:36 by chanwoki          #+#    #+#             */
/*   Updated: 2023/03/30 02:26:42 by chanwookim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_lst(t_ps *lst)
{
	size_t	i;
	t_deque	*temp;

	i = 0;
	if (lst->head == NULL)
		return (0);
	temp = lst->head;
	while (temp)
	{
		temp = temp->next;
		i++;
		if (i == 3)
			return (3);
	}
	if (i == 2)
		return (2);
	return (1);
}
