/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:37:28 by chanwoki          #+#    #+#             */
/*   Updated: 2022/11/10 20:09:10 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dptr;
	unsigned char	*sptr;

	if (dst == 0 && src == 0)
		return (0);
	i = 0;
	dptr = (unsigned char *)dst;
	sptr = (unsigned char *)src;
	if (sptr - dptr >= 0)
	{
		while (i < len)
		{
			dptr[i] = sptr[i];
			i++;
		}
	}
	else
	{
		i = ft_strlen(src) - 1;
		len = ft_strlen(dst) - 1;
		while (i >= 0)
		{
			dptr[len] = sptr[i];
			i--;
			len--;
		}
	}
	return (dptr);
}
