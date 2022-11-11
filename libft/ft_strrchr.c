/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:45:33 by chanwoki          #+#    #+#             */
/*   Updated: 2022/11/11 20:50:23 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	i;
	char	start;

	i = (char)c;
	start = *s;
	while (*s)
		s++;
	while (*s != i)
	{
		if (*s == start)
			return (0);
		s--;
	}
	return ((char *)s);
}
