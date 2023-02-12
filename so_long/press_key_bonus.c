/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:54:38 by chanwoki          #+#    #+#             */
/*   Updated: 2023/02/12 15:40:30 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	key_press(int keycode, t_param *param)
{
	int			y_max;
	int			x_max;
	static int	time[4];

	y_max = (param->height) * param->row;
	x_max = (param->width) * param->col;
	if (keycode == KEY_W && param->y != 0)
		press_w(param, time);
	else if (keycode == KEY_S && param->y < y_max - param->height)
		press_s(param, time);
	else if (keycode == KEY_A && param->x != 0)
		press_a(param, time);
	else if (keycode == KEY_D && param->x < x_max - param->width)
		press_d(param, time);
	else if (keycode == KEY_ESC)
		exit(0);
	check_score(param);
	if (param->walk % 4 == 0)
		printf("%d\n", param->walk / 4);
	return (0);
}

void	press_w(t_param *p, int *time)
{
	int	check;

	p->now = p->move.back1;
	time[0]++;
	check = p->start_x % p->width;
	if (time[0] >= 1 && time[0] < 3)
		p->now = p->move.back2;
	else if (time[0] >= 3 && time[0] < 5)
		p->now = p->move.back3;
	else if (time[0] >= 5 && time[0] < 7)
		p->now = p->move.back4;
	else if (time[0] >= 7 && time[0] < 9)
		p->now = p->move.back5;
	else if (time[0] >= 9 && time[0] < 11)
		p->now = p->move.back6;
	else if (time[0] >= 11)
	{
		p->now = p->move.back7;
		if (time[0] == 13)
			time[0] = 0;
	}
	check_wall_w(p, check);
}

void	press_a(t_param *p, int *time)
{
	int	check;

	p->now = p->move.left1;
	time[2]++;
	check = p->start_y % p->height;
	if (time[2] >= 1 && time[2] < 3)
		p->now = p->move.left2;
	else if (time[2] >= 3 && time[2] < 5)
		p->now = p->move.left3;
	else if (time[2] >= 5 && time[2] < 7)
		p->now = p->move.left4;
	else if (time[2] >= 7 && time[2] < 9)
		p->now = p->move.left5;
	else if (time[2] >= 9 && time[2] < 11)
		p->now = p->move.left6;
	else if (time[2] >= 11)
	{
		p->now = p->move.left7;
		if (time[2] == 13)
			time[2] = 0;
	}
	check_wall_a(p, check);
}

void	press_s(t_param *p, int *time)
{
	int	check;

	p->now = p->move.player;
	time[1]++;
	check = p->start_x % p->width;
	if (time[1] >= 1 && time[1] < 3)
		p->now = p->move.front1;
	else if (time[1] >= 3 && time[1] < 5)
		p->now = p->move.front2;
	else if (time[1] >= 5 && time[1] < 7)
		p->now = p->move.front3;
	else if (time[1] >= 7 && time[1] < 9)
		p->now = p->move.front4;
	else if (time[1] >= 9 && time[1] < 11)
		p->now = p->move.front5;
	else if (time[1] >= 11)
	{
		p->now = p->move.front6;
		if (time[1] == 13)
			time[1] = 0;
	}
	check_wall_s(p, check);
}

void	press_d(t_param *p, int *time)
{
	int	check;

	time[3]++;
	p->now = p->move.right1;
	check = p->start_y % p->height;
	if (time[3] >= 1 && time[3] < 3)
		p->now = p->move.right2;
	else if (time[3] >= 3 && time[3] < 5)
		p->now = p->move.right3;
	else if (time[3] >= 5 && time[3] < 7)
		p->now = p->move.right4;
	else if (time[3] >= 7 && time[3] < 9)
		p->now = p->move.right5;
	else if (time[3] >= 9 && time[3] < 11)
		p->now = p->move.right6;
	else if (time[3] >= 11)
	{
		p->now = p->move.right7;
		if (time[3] == 13)
			time[3] = 0;
	}
	check_wall_d(p, check);
}
