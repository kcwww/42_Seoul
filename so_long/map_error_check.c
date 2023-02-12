/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:40:11 by chanwoki          #+#    #+#             */
/*   Updated: 2023/02/10 16:38:45 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_size(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[0][j])
		j++;
	while (map[i])
		i++;
	if (j > 40 || i > 20)
		return (-1);
	return (1);
}

void	side_check(char **map, int *flag)
{
	int	i;
	int	j;

	j = ft_strlen(map[0]) - 1;
	i = 0;
	while (map[i])
	{
		if (map[i][j] != '1')
			*flag = 1;
		i++;
	}
	j = 0;
	i--;
	while (map[i][j])
	{
		if (map[i][j] != '1')
			*flag = 1;
		j++;
	}
	return ;
}

int	is_side_wall(char **map)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	while (map[i])
	{
		if (map[i][j] != '1')
			flag = 1;
		i++;
	}
	i = 0;
	while (map[i][j])
	{
		if (map[i][j] != '1')
			flag = 1;
		j++;
	}
	side_check(map, &flag);
	if (flag == 1)
		return (-1);
	return (1);
}

int	component_is(int *com)
{
	if (com[0] != 1)
		return (-1);
	if (com[1] == 0)
		return (-1);
	if (com[2] == 0)
		return (-1);
	return (1);
}

int	check_component(char **map)
{
	int	com[3];
	int	i;
	int	j;

	i = 0;
	ft_memset(com, 0, sizeof(int) * 3);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				com[0]++;
			else if (map[i][j] == 'E')
				com[1]++;
			else if (map[i][j] == 'C')
				com[2]++;
			else if (map[i][j] != '1' && map[i][j] != '0')
				return (-1);
			j++;
		}
		i++;
	}
	i = component_is(com);
	return (i);
}
