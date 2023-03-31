/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_str_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcw <kcw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 02:00:38 by chanwookim        #+#    #+#             */
/*   Updated: 2023/03/31 14:06:34 by kcw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*remove_newline(char *rule)
{
	int		len;
	int		idx;
	char	*str;

	len = ft_strlen(rule);
	idx = 0;
	str = (char *)malloc(sizeof(char) * len);
	if (str == NULL)
	{
		free(rule);
		return (NULL);
	}
	str[len - 1] = 0;
	while (idx + 1 < len)
	{
		str[idx] = rule[idx];
		idx++;
	}
	free_str(&rule);
	return (str);
}

int	check_str(char *rule)
{
	int	len;

	len = ft_strlen(rule);
	if (len > 4 || len == 0)
		return (-1);
	if (check_rules(rule) == 1)
		return (1);
	return (-1);
}
