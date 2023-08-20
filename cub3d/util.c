/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 17:08:52 by chanwoki          #+#    #+#             */
/*   Updated: 2023/08/20 17:22:37 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	idx;

	idx = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[idx] && s2[idx])
	{
		if (s1[idx] != s2[idx])
			return ((unsigned char)s1[idx] - (unsigned char)s2[idx]);
		idx++;
	}
	return ((unsigned char)s1[idx] - (unsigned char)s2[idx]);
}

int	ft_strlen(char *str)
{
	int	idx;

	if (!str)
		return (0);
	idx = 0;
	while (str[idx])
		idx++;
	return (idx);
}

int	ft_isalpha_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (2);
	if (c >= 'a' && c <= 'z')
		return (3);
	return (0);
}
