/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:24:43 by chanwoki          #+#    #+#             */
/*   Updated: 2023/02/12 15:39:38 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_param *param)
{
	int	i;

	i = 0;
	while (param->map[i])
	{
		free(param->map[i]);
		i++;
	}
	free(param->map);
	return ;
}

int	check_arg(int argc, char **argv)
{
	int		i;
	size_t	len;

	if (argc != 2)
		return (-1);
	len = ft_strlen(argv[1]);
	if (len < 5)
		return (-1);
	i = 0;
	while (argv[1][i])
		i++;
	i -= 4;
	if (ft_strncmp(&argv[1][i], ".ber", 4) == 0)
		return (1);
	return (-1);
}

int	is_map_square(char **map)
{
	int	i;
	int	j;
	int	len;

	len = 0;
	while (map[0][len])
		len++;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j != len)
			return (-1);
		i++;
	}
	return (1);
}

void	free_visit(int **visit, char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(visit[i]);
		i++;
	}
	free(visit);
	return ;
}
