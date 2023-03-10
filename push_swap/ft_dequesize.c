/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dequesize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 19:01:48 by chanwoki          #+#    #+#             */
/*   Updated: 2023/03/10 19:03:43 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_dequesize(t_deque *lst)
{
	int	i;

	i = 0;
	if (lst == NULL)
		return (i);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
