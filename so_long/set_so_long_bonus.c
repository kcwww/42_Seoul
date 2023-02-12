/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_so_long_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:46:13 by chanwoki          #+#    #+#             */
/*   Updated: 2023/02/12 15:40:35 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	set_parameter(t_param *p)
{
	int	w;
	int	h;

	w = p->width;
	h = p->height;
	p->col = ft_strlen(p->map[0]);
	p->row = 0;
	p->score = 0;
	p->walk = 0;
	while (p->map[p->row])
		p->row++;
	init_digit(p);
	init_coins(p);
	init_move(p);
	init_player(p);
	p->ground = input_img(p, "imgs/ground.xpm");
	p->obstacle = input_img(p, "imgs/obstacle.xpm");
	p->escape = input_img(p, "imgs/escape.xpm");
	p->win = mlx_new_window(p->mlx, w * p->col, h * p->row, "so_long");
	p->x = 0;
	p->y = 0;
}

void	set_octo_x_y(t_param *param)
{
	int	i;
	int	j;
	int	o;

	i = 0;
	o = 0;
	while (param->map[i])
	{
		j = 0;
		while (param->map[i][j])
		{
			if (param->map[i][j] == 'B')
			{
				param->octo.octo_x[o] = j * param->width;
				param->octo.octo_y[o] = i * param->height;
				param->octo.octo_flag[o] = 0;
				o++;
			}
			j++;
		}
		i++;
	}
}

int	mem_octo(t_param *param)
{
	param->octo.octo_x = (int *)malloc(sizeof(int) * param->octo.octos);
	if (param->octo.octo_x == NULL)
		return (0);
	param->octo.octo_y = (int *)malloc(sizeof(int) * param->octo.octos);
	if (param->octo.octo_y == NULL)
		return (0);
	param->octo.octo_flag = (int *)malloc(sizeof(int) * param->octo.octos);
	if (param->octo.octo_flag == NULL)
		return (0);
	set_octo_x_y(param);
	return (1);
}
