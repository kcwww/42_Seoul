/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 12:48:44 by chanwoki          #+#    #+#             */
/*   Updated: 2022/11/27 12:48:45 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_size;
	size_t	idx;

	idx = 0;
	src_size = ft_strlen(src);
	while (src[idx] && idx + 1 < dstsize)
	{
		dst[idx] = src[idx];
		idx++;
	}
	if (dstsize != 0)
		dst[idx] = 0;
	return (src_size);
}

char	*ft_strchr(const char *s, int c)
{
	char	i;

	if (s == 0)
		return (0);
	i = (char)c;
	while (*s != i)
	{
		if (*s == 0)
			return (0);
		s++;
	}
	return ((char *)s);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*re;
	size_t	i;
	size_t	j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	re = (char *)malloc(sizeof(char) * (i + j + 1));
	if (re == 0)
		return (0);
	ft_strlcpy(re, s1, i + 1);
	ft_strlcpy(re + i, s2, j + 1);
	return (re);
}
