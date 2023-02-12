/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_so_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 09:54:15 by chanwoki          #+#    #+#             */
/*   Updated: 2023/02/12 15:52:45 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_coins(t_param *param)
{
	param->coin.coin1 = input_img(param, "imgs/coin1.xpm");
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
			draw_img(p, p->ground, p->x, p->y);
			p->x += p->width;
			j++;
		}
			i++;
			p->y += p->height;
	}
}
