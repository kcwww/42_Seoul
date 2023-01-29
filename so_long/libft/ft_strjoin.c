/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:24:48 by chanwoki          #+#    #+#             */
/*   Updated: 2023/01/29 19:06:22 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
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

	if (s1 != NULL)
		free(s1);
	if (s2 != NULL)
		free(s2);
	return (re);
}
