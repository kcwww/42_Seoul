/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:09:55 by chanwoki          #+#    #+#             */
/*   Updated: 2023/02/12 15:57:36 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*input_img(t_param *p, char *str)
{
	void	*img;

	img = mlx_xpm_file_to_image(p->mlx, str, &p->width, &p->height);
	return (img);
}

void	init_player_lr(t_param *param)
{
	param->move.left1 = input_img(param, "imgs/left1.xpm");
	param->move.right1 = input_img(param, "imgs/right1.xpm");
}

void	init_player_fb(t_param *param)
{
	param->move.player = input_img(param, "imgs/player.xpm");
	param->move.back1 = input_img(param, "imgs/back1.xpm");
}

void	init_move(t_param *param)
{
	param->move.player = input_img(param, "imgs/player.xpm");
	param->now = param->move.player;
	init_player_lr(param);
	init_player_fb(param);
}

void	init_player(t_param *param)
{
	int	i;
	int	j;

	i = 0;
	param->y = 0;
	while (param->map[i])
	{
		j = 0;
		param->x = 0;
		while (param->map[i][j])
		{
			if (param->map[i][j] == 'P')
			{
				param->start_x = param->x;
				param->start_y = param->y;
			}
			j++;
			param->x += param->width;
		}
		i++;
		param->y += param->height;
	}
}
