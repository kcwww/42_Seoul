/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:40:33 by chanwoki          #+#    #+#             */
/*   Updated: 2023/02/10 16:37:38 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	**init_visit(char **map)
{
	int	i;
	int	j;
	int	**visit;

	i = 0;
	j = ft_strlen(map[i]);
	while (map[i])
		i++;
	visit = (int **)malloc(sizeof(int *) * i);
	if (visit == NULL)
		return (NULL);
	i = 0;
	while (map[i])
	{
		visit[i] = (int *)malloc(sizeof(int) * j);
		if (visit == NULL)
			return (NULL);
		i++;
	}
	zero_arr(visit, map);
	return (visit);
}

void	move_setting(t_idx *idx)
{
	idx->move[0][0] = 0;
	idx->move[0][1] = 1;
	idx->move[1][0] = 1;
	idx->move[1][1] = 0;
	idx->move[2][0] = 0;
	idx->move[2][1] = -1;
	idx->move[3][0] = -1;
	idx->move[3][1] = 0;
}

void	dfs_clear(int x, int y, char **map, t_dfs *dfs)
{
	t_idx	idx;

	ft_memset(&idx, 0, sizeof(t_idx));
	move_setting(&idx);
	if (dfs->visit[y][x] == 1)
		return ;
	if (map[y][x] == 'E')
		dfs->flag = 1;
	if (map[y][x] == 'C')
		dfs->map_coin++;
	else if (map[y][x] != '0' && map[y][x] != 'P' && map[y][x] != 'E')
		return ;
	idx.x = ft_strlen(map[0]);
	dfs->visit[y][x] = 1;
	while (map[idx.y])
		idx.y++;
	while (idx.i < 4)
	{
		idx.p = x + idx.move[idx.i][1];
		idx.q = y + idx.move[idx.i][0];
		if ((idx.p > 0 && idx.p < idx.x) && (idx.q > 0 && idx.q < idx.y))
			dfs_clear(idx.p, idx.q, map, dfs);
		idx.i++;
	}
}

int	check_clear(char **map)
{
	t_dfs	dfs;

	ft_memset(&dfs, 0, sizeof(t_dfs));
	dfs.visit = init_visit(map);
	if (dfs.visit == NULL)
		return (-1);
	dfs.flag = -1;
	while (map[dfs.y])
	{
		dfs.x = 0;
		while (map[dfs.y][dfs.x])
		{
			if (map[dfs.y][dfs.x] == 'P')
				dfs_clear(dfs.x, dfs.y, map, &dfs);
			else if (map[dfs.y][dfs.x] == 'C')
				dfs.coin++;
			dfs.x++;
		}
		dfs.y++;
	}
	if (dfs.map_coin != dfs.coin)
		dfs.flag = -1;
	free_visit(dfs.visit, map);
	return (dfs.flag);
}

void	zero_arr(int **visit, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			visit[i][j] = 0;
			j++;
		}
		i++;
	}
	return ;
}
