/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dequeclear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:04:20 by chanwoki          #+#    #+#             */
/*   Updated: 2023/02/16 13:36:45 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_dequeclear(t_ps **deque)
{
	t_deque	*temp;
	t_deque	*tclear;

	if (*deque == NULL)
		return ;
	tclear = (*deque)->head;
	temp = (*deque)->head;
	while (temp)
	{
		temp = temp->next;
		free(tclear);
		tclear = temp;
	}
}
