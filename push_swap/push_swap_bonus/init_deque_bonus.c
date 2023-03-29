/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_deque_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwookim <chanwookim@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:25:33 by chanwoki          #+#    #+#             */
/*   Updated: 2023/03/30 02:35:24 by chanwookim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	init_deque(int argc, char **argv, t_ps *a)
{
	int		i;
	t_deque	*lst;

	i = 2;
	lst = ft_dequenew(ft_atoi(argv[1]));
	if (lst == NULL)
		return (-1);
	a->head = lst;
	while (i < argc)
	{
		lst->next = ft_dequenew(ft_atoi(argv[i]));
		if (lst == NULL)
		{
			ft_dequeclear(a);
			return (-1);
		}
		lst->next->previous = lst;
		lst = lst->next;
		i++;
	}
	a->tail = lst;
	return (1);
}
