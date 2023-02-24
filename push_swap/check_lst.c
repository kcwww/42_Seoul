/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:24:36 by chanwoki          #+#    #+#             */
/*   Updated: 2023/02/16 15:01:35 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
