/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:55:45 by chanwoki          #+#    #+#             */
/*   Updated: 2023/02/12 15:46:47 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_wall_d(t_param *p, int check)
{
	int	x;
	int	y;

	x = p->start_x;
	y = p->start_y;
	if (check == 0)
	{
		if (p->map[y / p->height][(x / p->width) + 1] != '1')
		{
			p->start_x += (p->width);
			p->walk++;
		}
	}
	else
	{
		if (p->map[(y - check) / p->height][(x / p->width) + 1] != '1' && \
		p->map[(y - check + p->height) / p->height][(x / p->width) + 1] != '1')
		{
			p->start_x += (p->width);
			p->walk++;
		}
	}
}

void	check_wall_s(t_param *p, int check)
{
	int	x;
	int	y;

	x = p->start_x;
	y = p->start_y;
	if (check == 0)
	{
		if (p->map[(y / p->height) + 1][x / p->width] != '1')
		{
			p->start_y += (p->height);
			p->walk++;
		}
	}
	else
	{
		if (p->map[(y / p->height) + 1][(x - check) / p->width] != '1' && \
		p->map[(y / p->height) + 1][(x - check + p->width) / p->width] != '1')
		{
			p->start_y += (p->height);
			p->walk++;
		}
	}
}

void	check_wall_a(t_param *p, int check)
{
	int	x;
	int	y;

	x = p->start_x;
	y = p->start_y;
	if (check == 0)
	{
		if (p->map[y / p->height][(x - 1) / p->width] != '1')
		{
			p->start_x -= (p->width);
			p->walk++;
		}
	}
	else
	{
		if (p->map[(y - check) / p->height][(x - 1) / p->width] != '1' && \
		p->map[(y - check + p->height) / p->height][(x - 1) / p->width] != '1')
		{
			p->start_x -= (p->width);
			p->walk++;
		}
	}
}

void	check_wall_w(t_param *p, int check)
{
	int	x;
	int	y;

	x = p->start_x;
	y = p->start_y;
	if (check == 0)
	{
		if (p->map[(y - 1) / p->height][x / p->width] != '1')
		{
			p->start_y -= (p->height);
			p->walk++;
		}
	}
	else
	{
		if (p->map[(y - 1) / p->height][(x - check) / p->width] != '1' && \
		p->map[(y - 1) / p->height][(x - check + p->width) / p->width] != '1')
		{
			p->start_y -= (p->height);
			p->walk++;
		}
	}
}
