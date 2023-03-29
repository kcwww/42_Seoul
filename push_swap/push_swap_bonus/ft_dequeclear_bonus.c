/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dequeclear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwookim <chanwookim@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:04:20 by chanwoki          #+#    #+#             */
/*   Updated: 2023/03/30 01:52:28 by chanwookim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_dequeclear(t_ps *deque)
{
	t_deque	*temp;
	t_deque	*tclear;

	if (deque == NULL)
		return ;
	tclear = deque->head;
	temp = deque->head;
	while (temp)
	{
		temp = temp->next;
		free(tclear);
		tclear = temp;
	}
}
