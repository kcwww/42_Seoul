/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:24:36 by chanwoki          #+#    #+#             */
/*   Updated: 2023/01/18 15:26:04 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_lst(t_list *lst)
{
	size_t	i;
	t_list	*temp;

	i = 1;
	temp = lst;
	if (lst == 0)
		return (0);
	if (temp->next)
	{
		lst = lst->next;
		temp = lst;
		i++;
	}
	return (i);
}
