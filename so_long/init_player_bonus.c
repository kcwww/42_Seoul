/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:09:55 by chanwoki          #+#    #+#             */
/*   Updated: 2023/02/12 15:39:26 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	*input_img(t_param *p, char *str)
{
	void	*img;

	img = mlx_xpm_file_to_image(p->mlx, str, &p->width, &p->height);
	return (img);
}

void	init_player_lr(t_param *param)
{
	param->move.left1 = input_img(param, "imgs/left1.xpm");
	param->move.left2 = input_img(param, "imgs/left2.xpm");
	param->move.left3 = input_img(param, "imgs/left3.xpm");
	param->move.left4 = input_img(param, "imgs/left4.xpm");
	param->move.left5 = input_img(param, "imgs/left5.xpm");
	param->move.left6 = input_img(param, "imgs/left6.xpm");
	param->move.left7 = input_img(param, "imgs/left7.xpm");
	param->move.right1 = input_img(param, "imgs/right1.xpm");
	param->move.right2 = input_img(param, "imgs/right2.xpm");
	param->move.right3 = input_img(param, "imgs/right3.xpm");
	param->move.right4 = input_img(param, "imgs/right4.xpm");
	param->move.right5 = input_img(param, "imgs/right5.xpm");
	param->move.right6 = input_img(param, "imgs/right6.xpm");
	param->move.right7 = input_img(param, "imgs/right7.xpm");
}

void	init_player_fb(t_param *param)
{
	param->move.front1 = input_img(param, "imgs/front1.xpm");
	param->move.front2 = input_img(param, "imgs/front2.xpm");
	param->move.front3 = input_img(param, "imgs/front3.xpm");
	param->move.front4 = input_img(param, "imgs/front4.xpm");
	param->move.front5 = input_img(param, "imgs/front5.xpm");
	param->move.front6 = input_img(param, "imgs/front6.xpm");
	param->move.back1 = input_img(param, "imgs/back1.xpm");
	param->move.back2 = input_img(param, "imgs/back2.xpm");
	param->move.back3 = input_img(param, "imgs/back3.xpm");
	param->move.back4 = input_img(param, "imgs/back4.xpm");
	param->move.back5 = input_img(param, "imgs/back5.xpm");
	param->move.back6 = input_img(param, "imgs/back6.xpm");
	param->move.back7 = input_img(param, "imgs/back7.xpm");
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
