/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 23:05:20 by chanwoki          #+#    #+#             */
/*   Updated: 2022/11/18 00:19:19 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*start;

	if (lst == 0 || *lst == 0)
		return ;
	start = *lst;
	while (start)
	{
		(*lst) = (*lst)->next;
		ft_lstdelone(start, del);
		start = *lst;
	}
}
