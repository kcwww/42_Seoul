/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_walk_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:07:47 by chanwoki          #+#    #+#             */
/*   Updated: 2023/02/12 15:40:46 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_digit(char c, t_param *p, float i)
{
	int	w;
	int	h;

	w = p->width;
	h = p->height;
	if (c == '0')
		draw_img(p, p->digit.zero, (p->col - i) * w, h / 4);
	else if (c == '1')
		draw_img(p, p->digit.one, (p->col - i) * w, h / 4);
	else if (c == '2')
		draw_img(p, p->digit.two, (p->col - i) * w, h / 4);
	else if (c == '3')
		draw_img(p, p->digit.three, (p->col - i) * w, h / 4);
	else if (c == '4')
		draw_img(p, p->digit.four, (p->col - i) * w, h / 4);
	else if (c == '5')
		draw_img(p, p->digit.five, (p->col - i) * w, h / 4);
	else if (c == '6')
		draw_img(p, p->digit.six, (p->col - i) * w, h / 4);
	else if (c == '7')
		draw_img(p, p->digit.seven, (p->col - i) * w, h / 4);
	else if (c == '8')
		draw_img(p, p->digit.eight, (p->col - i) * w, h / 4);
	else if (c == '9')
		draw_img(p, p->digit.nine, (p->col - i) * w, h / 4);
}

void	draw_walk(t_param *param)
{
	char	*num;
	int		len;
	float	x_w;

	num = ft_itoa(param->walk / 4);
	len = ft_strlen(num);
	x_w = 0.75;
	while (len-- > 0)
	{
		draw_digit(num[len], param, x_w);
		x_w += 1;
	}
	free(num);
}

void	check_score(t_param *p)
{
	if (p->map[p->y / p->height][p->x / p->width] == 'C')
	{
		p->map[p->y / p->height][p->x / p->width] = 'P';
		p->score++;
	}
	else if (p->map[p->y / p->height][p->x / p->width] == 'E')
	{
		if (p->score == p->all_coins)
			exit (0);
	}
}
