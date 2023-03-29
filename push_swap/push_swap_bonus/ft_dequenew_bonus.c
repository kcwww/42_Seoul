/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dequenew_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwookim <chanwookim@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:45:07 by chanwoki          #+#    #+#             */
/*   Updated: 2023/03/30 02:29:02 by chanwookim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_deque	*ft_dequenew(int content)
{
	t_deque	*re;

	re = (t_deque *)malloc(sizeof(t_deque));
	if (re == NULL)
		return (NULL);
	re->content = content;
	re->next = NULL;
	re->previous = NULL;
	return (re);
}
