/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:09:45 by chanwoki          #+#    #+#             */
/*   Updated: 2023/02/10 16:19:24 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_one(t_param *param)
{
	if (is_map_square(param->map) == -1)
	{
		free_map(param);
		printf("Error\nMap is not square.\n");
		return (0);
	}
	if (check_map_size(param->map) == -1)
	{
		free_map(param);
		printf("Error\nMap is too big.\n");
		return (0);
	}
	return (1);
}

int	error_two(t_param *param)
{
	if (is_side_wall(param->map) == -1)
	{
		free_map(param);
		printf("Error\nSide is not wall.\n");
		return (0);
	}
	if (check_component(param->map) == -1)
	{
		free_map(param);
		printf("Error\nWrong Component.\n");
		return (0);
	}
	if (check_clear(param->map) == -1)
	{
		free_map(param);
		printf("Error\nImpossible Game.\n");
		return (0);
	}
	return (1);
}

int	check_map_error(t_param *param)
{
	if (error_one(param) == 0)
		return (0);
	if (error_two(param) == 0)
		return (0);
	return (1);
}

int	map_and_error(t_param *param, int fd)
{
	if (get_map(param, fd) == 0)
		return (-1);
	if (param->map[0] == NULL)
	{
		free_map(param);
		printf("Error\nEmpty file.\n");
		return (-1);
	}
	if (check_map_error(param) == 0)
		return (-1);
	return (1);
}
