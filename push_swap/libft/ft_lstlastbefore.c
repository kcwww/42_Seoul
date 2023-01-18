/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlastbefore.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:10:49 by chanwoki          #+#    #+#             */
/*   Updated: 2023/01/18 15:11:10 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlastbefore(t_list *lst)
{
	if (lst == 0)
		return (0);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}
