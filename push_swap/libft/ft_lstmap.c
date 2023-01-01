/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 00:11:47 by chanwoki          #+#    #+#             */
/*   Updated: 2022/11/18 01:22:26 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*init_lst(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*ptr;
	t_list	*link_li;

	ptr = (*f)(lst->content);
	link_li = ft_lstnew(ptr);
	if (link_li == 0)
	{
		(*del)(ptr);
		return (0);
	}
	return (link_li);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*link_li;
	t_list	*start;
	void	*ptr;

	if (lst == 0 || f == 0 || del == 0)
		return (0);
	link_li = init_lst(lst, f, del);
	if (link_li == 0)
		return (0);
	start = link_li;
	lst = lst->next;
	while (lst)
	{
		ptr = (*f)(lst->content);
		link_li->next = ft_lstnew(ptr);
		if (link_li->next == 0)
		{
			(*del)(ptr);
			ft_lstclear(&start, del);
			return (0);
		}
		link_li = link_li->next;
		lst = lst->next;
	}
	return (start);
}
