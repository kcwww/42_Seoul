/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_so_long_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:54:15 by chanwoki          #+#    #+#             */
/*   Updated: 2023/02/12 15:39:31 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_coins(t_param *param)
{
	param->coin.coin1 = input_img(param, "imgs/coin1.xpm");
	param->coin.coin2 = input_img(param, "imgs/coin2.xpm");
	param->coin.coin3 = input_img(param, "imgs/coin3.xpm");
	param->coin.coin4 = input_img(param, "imgs/coin4.xpm");
}

void	init_digit(t_param *param)
{
	param->digit.zero = input_img(param, "imgs/0.xpm");
	param->digit.one = input_img(param, "imgs/1.xpm");
	param->digit.two = input_img(param, "imgs/2.xpm");
	param->digit.three = input_img(param, "imgs/3.xpm");
	param->digit.four = input_img(param, "imgs/4.xpm");
	param->digit.five = input_img(param, "imgs/5.xpm");
	param->digit.six = input_img(param, "imgs/6.xpm");
	param->digit.seven = input_img(param, "imgs/7.xpm");
	param->digit.eight = input_img(param, "imgs/8.xpm");
	param->digit.nine = input_img(param, "imgs/9.xpm");
}

void	init_octo(t_param *param)
{
	param->octo.octos = 0;
	param->octo.octo1 = input_img(param, "imgs/octo1.xpm");
	param->octo.octo2 = input_img(param, "imgs/octo2.xpm");
	param->octo.octoleft1 = input_img(param, "imgs/octoleft1.xpm");
	param->octo.octoleft2 = input_img(param, "imgs/octoleft2.xpm");
	param->octo.octoright1 = input_img(param, "imgs/octoright1.xpm");
	param->octo.octoright2 = input_img(param, "imgs/octoright2.xpm");
	param->octo.octoback1 = input_img(param, "imgs/octoback1.xpm");
	param->octo.octoback2 = input_img(param, "imgs/octoback2.xpm");
}

void	init_map(t_param *p)
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
			mlx_put_image_to_window(p->mlx, p->win, p->ground, p->x, p->y);
			p->x += p->width;
			j++;
		}
			i++;
			p->y += p->height;
	}
}
