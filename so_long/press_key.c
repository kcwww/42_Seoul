/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:54:38 by chanwoki          #+#    #+#             */
/*   Updated: 2023/02/12 15:59:33 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_param *param)
{
	int			y_max;
	int			x_max;

	y_max = (param->height) * param->row;
	x_max = (param->width) * param->col;
	if (keycode == KEY_W && param->y != 0)
		press_w(param);
	else if (keycode == KEY_S && param->y < y_max - param->height)
		press_s(param);
	else if (keycode == KEY_A && param->x != 0)
		press_a(param);
	else if (keycode == KEY_D && param->x < x_max - param->width)
		press_d(param);
	else if (keycode == KEY_ESC)
		exit(0);
	check_score(param);
	printf("%d\n", param->walk);
	return (0);
}

void	press_w(t_param *p)
{
	int	check;

	p->now = p->move.back1;
	check = p->start_x % p->width;
	check_wall_w(p, check);
}

void	press_a(t_param *p)
{
	int	check;

	p->now = p->move.left1;
	check = p->start_y % p->height;
	check_wall_a(p, check);
}

void	press_s(t_param *p)
{
	int	check;

	p->now = p->move.player;
	check = p->start_x % p->width;
	check_wall_s(p, check);
}

void	press_d(t_param *p)
{
	int	check;

	p->now = p->move.right1;
	check = p->start_y % p->height;
	check_wall_d(p, check);
}
