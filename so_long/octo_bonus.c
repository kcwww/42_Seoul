/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octo_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:05:37 by chanwoki          #+#    #+#             */
/*   Updated: 2023/02/12 15:40:25 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_octo_y(t_param *p, int i)
{
	int	h;
	int	w;

	w = p->width;
	h = p->height;
	if (p->octo.octo_flag[i] == 0)
	{
		p->octo.octo_y[i] += (h / 16);
		if (p->map[(p->octo.octo_y[i] / h) + 1][p->octo.octo_x[i] / w] == '1')
			p->octo.octo_flag[i] = 1;
	}
	else if (p->octo.octo_flag[i] == 2)
	{
		p->octo.octo_y[i] -= (h / 16);
		if (p->map[(p->octo.octo_y[i] - 1) / h][p->octo.octo_x[i] / w] == '1')
			p->octo.octo_flag[i] = 3;
	}
}

void	move_octo_x(t_param *p, int i)
{
	int	h;
	int	w;

	w = p->width;
	h = p->height;
	if (p->octo.octo_flag[i] == 1)
	{
		p->octo.octo_x[i] += (w / 16);
		if (p->map[(p->octo.octo_y[i] / h)][(p->octo.octo_x[i] / w) + 1] == '1')
			p->octo.octo_flag[i] = 2;
	}
	else if (p->octo.octo_flag[i] == 3)
	{
		p->octo.octo_x[i] -= (w / 16);
		if (p->map[p->octo.octo_y[i] / h][(p->octo.octo_x[i] - 1) / w] == '1')
			p->octo.octo_flag[i] = 0;
	}
}

void	move_octo(t_param *param)
{
	int	i;

	i = 0;
	while (i < param->octo.octos)
	{
		move_octo_y(param, i);
		move_octo_x(param, i);
		i++;
	}
}

void	draw_octo_fb(t_param *param, int i)
{
	static int	time;

	if (param->octo.octo_flag[i] == 0)
	{
		if (time < 24)
			draw_octo_img(param, param->octo.octo1, i);
		else
			draw_octo_img(param, param->octo.octo2, i);
	}
	else if (param->octo.octo_flag[i] == 2)
	{
		if (time < 24)
			draw_octo_img(param, param->octo.octoback1, i);
		else
			draw_octo_img(param, param->octo.octoback2, i);
	}
	time++;
	if (time == 48)
		time = 0;
}

void	draw_octo_lr(t_param *param, int i)
{
	static int	time;

	if (param->octo.octo_flag[i] == 1)
	{
		if (time < 24)
			draw_octo_img(param, param->octo.octoright1, i);
		else
			draw_octo_img(param, param->octo.octoright2, i);
	}
	else if (param->octo.octo_flag[i] == 3)
	{
		if (time < 24)
			draw_octo_img(param, param->octo.octoleft1, i);
		else
			draw_octo_img(param, param->octo.octoleft2, i);
	}
	time++;
	if (time == 48)
		time = 0;
}
