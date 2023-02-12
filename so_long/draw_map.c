/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:01:18 by chanwoki          #+#    #+#             */
/*   Updated: 2023/02/12 16:04:01 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_coins(t_param *p)
{
	if (p->x == p->start_x && p->y == p->start_y)
		return ;
	draw_img(p, p->coin.coin1, p->x, p->y);
}

void	draw_component(t_param *p)
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
				draw_coins(p);
			p->x += p->width;
			j++;
		}
		i++;
		p->y += p->height;
	}
}

int	draw_map(t_param *p)
{
	mlx_clear_window(p->mlx, p->win);
	init_map(p);
	draw_component(p);
	draw_img(p, p->now, p->start_x, p->start_y);
	p->x = p->start_x;
	p->y = p->start_y;
	return (0);
}
