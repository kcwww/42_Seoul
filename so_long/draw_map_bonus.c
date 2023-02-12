/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:01:18 by chanwoki          #+#    #+#             */
/*   Updated: 2023/02/12 16:22:40 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_octo(t_param *param)
{
	int	i;

	i = 0;
	while (i < param->octo.octos)
	{
		draw_octo_fb(param, i);
		draw_octo_lr(param, i);
		i++;
	}
}

void	draw_coins(t_param *p, int *time)
{
	if (*time < 3)
	{
		draw_img(p, p->ground, p->x, p->y);
		draw_img(p, p->coin.coin2, p->x, p->y);
	}
	else if (*time >= 3 && *time < 6)
	{
		draw_img(p, p->ground, p->x, p->y);
		draw_img(p, p->coin.coin3, p->x, p->y);
	}
	else if (*time >= 6 && *time < 26)
	{
		draw_img(p, p->ground, p->x, p->y);
		draw_img(p, p->coin.coin4, p->x, p->y);
	}
	else if (*time >= 26)
	{
		draw_img(p, p->ground, p->x, p->y);
		draw_img(p, p->coin.coin1, p->x, p->y);
	}
}

void	draw_component(t_param *p, int *time)
{
	int	i;
	int	j;

	i = 0;
	p->y = 0;
	while (p->map[i])
	{
		j = 0;
		p->x = 0;
		while (p->map[i][j])
		{
			if (p->map[i][j] == '1')
				draw_img(p, p->obstacle, p->x, p->y);
			else if (p->map[i][j] == '0')
				draw_img(p, p->ground, p->x, p->y);
			else if (p->map[i][j] == 'E')
				draw_img(p, p->escape, p->x, p->y);
			else if (p->map[i][j] == 'C')
				draw_coins(p, time);
			p->x += p->width;
			j++;
		}
		i++;
		p->y += p->height;
	}
}

int	draw_map(t_param *p)
{
	static int	time;

	time++;
	mlx_clear_window(p->mlx, p->win);
	init_map(p);
	move_octo(p);
	draw_component(p, &time);
	draw_octo(p);
	draw_img(p, p->now, p->start_x, p->start_y);
	if (time > 45)
		time = 0;
	draw_walk(p);
	p->x = p->start_x;
	p->y = p->start_y;
	dead_check(p);
	return (0);
}

void	dead_check(t_param *param)
{
	int	i;

	i = 0;
	while (i < param->octo.octos)
	{
		if (param->x < (param->octo.octo_x[i] + 32) && \
		param->x > (param->octo.octo_x[i] - 32) && \
		param->y < (param->octo.octo_y[i] + 32) && \
		param->y > (param->octo.octo_y[i] - 32))
		{
			printf("GAME OVER\n");
			exit (0);
		}
		i++;
	}
}
