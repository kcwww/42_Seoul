/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_so_long.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:46:13 by chanwoki          #+#    #+#             */
/*   Updated: 2023/02/10 16:50:56 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_parameter(t_param *p)
{
	int	w;
	int	h;

	w = 64;
	h = 64;
	p->col = ft_strlen(p->map[0]);
	p->row = 0;
	p->score = 0;
	p->walk = 0;
	while (p->map[p->row])
		p->row++;
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
