/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 12:48:44 by chanwoki          #+#    #+#             */
/*   Updated: 2022/12/01 20:47:26 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlcpy(char *dst, char *src, int dstsize)
{
	int	src_size;
	int	idx;

	idx = 0;
	if (src == 0)
		return (0);
	src_size = ft_strlen(src);
	while (src[idx] && idx < dstsize - 1)
	{
		dst[idx] = src[idx];
		idx++;
	}
	if (dstsize != 0)
		dst[idx] = 0;
	return (src_size);
}

char	*ft_strchr(char *s, int c)
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

int	ft_strlen(char *s)
{
	int	i;

	if (s == 0)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*re;
	int		i;
	int		j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	re = (char *)malloc(sizeof(char) * (i + j + 1));
	if (re == 0)
		return (0);
	ft_strlcpy(re, s1, i + 1);
	ft_strlcpy(re + i, s2, j + 1);
	// s1 프리해주고 리턴
	return (re);
}

// void free_str(char *string)
// {
// 	free(string);
// 	string = NULL;
// }
// 프리해주고 초기화
