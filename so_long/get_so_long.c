/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_so_long.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:48:00 by chanwoki          #+#    #+#             */
/*   Updated: 2023/02/10 16:42:19 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_one_line(int fd)
{
	char	*str;
	char	*parse;

	str = NULL;
	parse = get_next_line(fd);
	while (parse != NULL)
	{
		str = ft_strjoin(str, parse);
		if (str == NULL)
		{
			printf("Error\n%s\n", strerror(errno));
			return (NULL);
		}
		parse = get_next_line(fd);
	}
	if (str == NULL)
		printf("Error\nEmpty File\n");
	return (str);
}

int	get_map(t_param *param, int fd)
{
	char	*str;

	str = get_one_line(fd);
	if (str == NULL)
		return (0);
	param->map = ft_split(str, '\n');
	free(str);
	if (param->map == NULL)
	{
		printf("Error\n%s\n", strerror(errno));
		return (0);
	}
	return (1);
}

void	get_coin(t_param *param)
{
	int	i;
	int	j;

	i = 0;
	param->all_coins = 0;
	while (param->map[i])
	{
		j = 0;
		while (param->map[i][j])
		{
			if (param->map[i][j] == 'C')
				param->all_coins += 1;
			j++;
		}
		i++;
	}
}
