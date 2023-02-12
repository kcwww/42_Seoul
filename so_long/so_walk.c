/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_walk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 14:07:47 by chanwoki          #+#    #+#             */
/*   Updated: 2023/02/10 16:43:39 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
