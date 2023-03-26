/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_deque.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:25:33 by chanwoki          #+#    #+#             */
/*   Updated: 2023/03/26 23:56:21 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_deque(int argc, char **argv, t_ps *A)
{
	int		i;
	t_deque	*lst;

	i = 2;
	lst = ft_dequenew(ft_atoi(argv[1]));
	if (lst == NULL)
		return (-1);
	A->head = lst;
	while (i < argc)
	{
		lst->next = ft_dequenew(ft_atoi(argv[i]));
		if (lst == NULL)
		{
			ft_dequeclear(A);
			return (-1);
		}
		lst->next->previous = lst;
		lst = lst->next;
		i++;
	}
	A->tail = lst;
	return (1);
}
