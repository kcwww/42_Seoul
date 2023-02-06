/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 13:38:44 by chanwoki          #+#    #+#             */
/*   Updated: 2023/02/06 14:28:28 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "mlx/mlx.h"
#include "so_long.h"
#include <stdio.h>
#include <time.h>
///////////////////////////////////////////

void check_leaks(void)
{
	system("leaks so_long");
}


int	draw_map(t_param *param)
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
			if (param->map[i][j] == '1')
				mlx_put_image_to_window(param->mlx, param->win, param->obstacle, param->x, param->y);
			else if (param->map[i][j] == '0')
				mlx_put_image_to_window(param->mlx, param->win, param->ground, param->x, param->y);
			else if (param->map[i][j] == 'E')
				mlx_put_image_to_window(param->mlx, param->win, param->escape, param->x, param->y);
			else if (param->map[i][j] == 'C')
				mlx_put_image_to_window(param->mlx, param->win, param->coin.coin1, param->x, param->y);
			else if (param->map[i][j] == 'P')
			{
				if (param->goal == -1)
					mlx_put_image_to_window(param->mlx, param->win, param->escape, param->x, param->y);
				else
					mlx_put_image_to_window(param->mlx, param->win, param->ground, param->x, param->y);
				param->start_x = param->x;
				param->start_y = param->y;
				mlx_put_image_to_window(param->mlx, param->win, param->move.player, param->x, param->y);
			}
			param->x += param->width;
			j++;
		}
			i++;
			param->y += param->height;
		}
	param->x = param->start_x;
	param->y = param->start_y;
	return (0);
}

int	key_press(int keycode, t_param *param)
{
	int	y_max;
	int	x_max;

	y_max = (param->height) * param->row;
	x_max = (param->width) * param->col;
	if (keycode == KEY_W && param->y != 0)
	{
		if (param->map[param->y / param->height - 1][param->x / param->width] != '1')
		{
			if (param->goal == -1)
			{
				param->goal = 0;
				param->map[param->y / param->height][param->x / param->width] = 'E';
			}
			else
				param->map[param->y / param->height][param->x / param->width] = '0';
			param->y -= param->height;
			param->walk++;
		}
	}
	else if (keycode == KEY_S && param->y < y_max - param->height)
	{
		if (param->map[param->y / param->height + 1][param->x / param->width] != '1')
		{
			if (param->goal == -1)
			{
				param->goal = 0;
				param->map[param->y / param->height][param->x / param->width] = 'E';
			}
			else
				param->map[param->y / param->height][param->x / param->width] = '0';
			param->y += param->height;
			param->walk++;
		}
	}
	else if (keycode == KEY_A && param->x != 0)
	{
		if (param->map[param->y / param->height][param->x / param->width - 1] != '1')
		{
			if (param->goal == -1)
			{
				param->goal = 0;
				param->map[param->y / param->height][param->x / param->width] = 'E';
			}
			else
				param->map[param->y / param->height][param->x / param->width] = '0';
			param->x -= param->width;
			param->walk++;
		}
	}
	else if (keycode == KEY_D && param->x < x_max - param->width)
	{
		if (param->map[param->y / param->height][param->x / param->width + 1] != '1')
		{
			if (param->goal == -1)
			{
				param->goal = 0;
				param->map[param->y / param->height][param->x / param->width] = 'E';
			}
			else
				param->map[param->y / param->height][param->x / param->width] = '0';
			param->x += param->width;
			param->walk++;
		}
	}
	else if (keycode == KEY_ESC)
		exit(0);
	if (param->map[param->y / param->height][param->x / param->width] == 'C')
		param->score++;
	else if (param->map[param->y / param->height][param->x / param->width] == 'E')
	{
		if (param->score == param->all_coins)
			param->goal = 1;
		else
			param->goal = -1;
	}
	param->map[param->y / param->height][param->x / param->width] = 'P';
	if (param->goal == 1)
		exit (0);
	printf("%d\n", param->walk);
	return (0);
}

int ft_close(void)
{
	exit (0);
	return (0);
}

void	init_digit(t_param *param)
{
	param->digit.zero = mlx_xpm_file_to_image(param->mlx, "imgs/0.xpm", &param->width, &param->height);
	param->digit.one = mlx_xpm_file_to_image(param->mlx, "imgs/1.xpm", &param->width, &param->height);
	param->digit.two = mlx_xpm_file_to_image(param->mlx, "imgs/2.xpm", &param->width, &param->height);
	param->digit.three = mlx_xpm_file_to_image(param->mlx, "imgs/3.xpm", &param->width, &param->height);
	param->digit.four = mlx_xpm_file_to_image(param->mlx, "imgs/4.xpm", &param->width, &param->height);
	param->digit.five = mlx_xpm_file_to_image(param->mlx, "imgs/5.xpm", &param->width, &param->height);
	param->digit.six = mlx_xpm_file_to_image(param->mlx, "imgs/6.xpm", &param->width, &param->height);
	param->digit.seven = mlx_xpm_file_to_image(param->mlx, "imgs/7.xpm", &param->width, &param->height);
	param->digit.eight = mlx_xpm_file_to_image(param->mlx, "imgs/8.xpm", &param->width, &param->height);
	param->digit.nine = mlx_xpm_file_to_image(param->mlx, "imgs/9.xpm", &param->width, &param->height);
}

int	key_release(int keycode, t_param *param)
{
	if (keycode == KEY_W)
		param->kflag[0] = 0;
	else if (keycode == KEY_A)
		param->kflag[1] = 0;
	else if (keycode == KEY_S)
		param->kflag[2] = 0;
	else if (keycode == KEY_D)
		param->kflag[3] = 0;
	return (0);
}

void	init_map(t_param *param)
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
			mlx_put_image_to_window(param->mlx, param->win, param->ground, param->x, param->y);
			param->x += param->width;
			j++;
		}
			i++;
			param->y += param->height;
	}
}

void	init_coins(t_param *param)
{
	param->coin.coin1 = mlx_xpm_file_to_image(param->mlx, "imgs/coin1.xpm", &param->width, &param->height);
	param->coin.coin2 = mlx_xpm_file_to_image(param->mlx, "imgs/coin2.xpm", &param->width, &param->height);
	param->coin.coin3 = mlx_xpm_file_to_image(param->mlx, "imgs/coin3.xpm", &param->width, &param->height);
	param->coin.coin4 = mlx_xpm_file_to_image(param->mlx, "imgs/coin4.xpm", &param->width, &param->height);
}

void	init_move(t_param *param)
{
	param->move.player = mlx_xpm_file_to_image(param->mlx, "imgs/player.xpm", &param->width, &param->height);
	param->move.front1 = mlx_xpm_file_to_image(param->mlx, "imgs/front1.xpm", &param->width, &param->height);
	param->move.front2 = mlx_xpm_file_to_image(param->mlx, "imgs/front2.xpm", &param->width, &param->height);
	param->move.front3 = mlx_xpm_file_to_image(param->mlx, "imgs/front3.xpm", &param->width, &param->height);
	param->move.front4 = mlx_xpm_file_to_image(param->mlx, "imgs/front4.xpm", &param->width, &param->height);
	param->move.front5 = mlx_xpm_file_to_image(param->mlx, "imgs/front5.xpm", &param->width, &param->height);
	param->move.front6 = mlx_xpm_file_to_image(param->mlx, "imgs/front6.xpm", &param->width, &param->height);
	param->move.left1 = mlx_xpm_file_to_image(param->mlx, "imgs/left1.xpm", &param->width, &param->height);
	param->move.left2 = mlx_xpm_file_to_image(param->mlx, "imgs/left2.xpm", &param->width, &param->height);
	param->move.left3 = mlx_xpm_file_to_image(param->mlx, "imgs/left3.xpm", &param->width, &param->height);
	param->move.left4 = mlx_xpm_file_to_image(param->mlx, "imgs/left4.xpm", &param->width, &param->height);
	param->move.left5 = mlx_xpm_file_to_image(param->mlx, "imgs/left5.xpm", &param->width, &param->height);
	param->move.left6 = mlx_xpm_file_to_image(param->mlx, "imgs/left6.xpm", &param->width, &param->height);
	param->move.left7 = mlx_xpm_file_to_image(param->mlx, "imgs/left7.xpm", &param->width, &param->height);
	param->move.right1 = mlx_xpm_file_to_image(param->mlx, "imgs/right1.xpm", &param->width, &param->height);
	param->move.right2 = mlx_xpm_file_to_image(param->mlx, "imgs/right2.xpm", &param->width, &param->height);
	param->move.right3 = mlx_xpm_file_to_image(param->mlx, "imgs/right3.xpm", &param->width, &param->height);
	param->move.right4 = mlx_xpm_file_to_image(param->mlx, "imgs/right4.xpm", &param->width, &param->height);
	param->move.right5 = mlx_xpm_file_to_image(param->mlx, "imgs/right5.xpm", &param->width, &param->height);
	param->move.right6 = mlx_xpm_file_to_image(param->mlx, "imgs/right6.xpm", &param->width, &param->height);
	param->move.right7 = mlx_xpm_file_to_image(param->mlx, "imgs/right7.xpm", &param->width, &param->height);
	param->move.back1 = mlx_xpm_file_to_image(param->mlx, "imgs/back1.xpm", &param->width, &param->height);
	param->move.back2 = mlx_xpm_file_to_image(param->mlx, "imgs/back2.xpm", &param->width, &param->height);
	param->move.back3 = mlx_xpm_file_to_image(param->mlx, "imgs/back3.xpm", &param->width, &param->height);
	param->move.back4 = mlx_xpm_file_to_image(param->mlx, "imgs/back4.xpm", &param->width, &param->height);
	param->move.back5 = mlx_xpm_file_to_image(param->mlx, "imgs/back5.xpm", &param->width, &param->height);
	param->move.back6 = mlx_xpm_file_to_image(param->mlx, "imgs/back6.xpm", &param->width, &param->height);
	param->move.back7 = mlx_xpm_file_to_image(param->mlx, "imgs/back7.xpm", &param->width, &param->height);
}

int main()
{
	t_param	param;
	char	*parse;
	char	*str;
	int		fd;
	int		i,j;

	fd = open("map.txt", O_RDONLY);
	atexit(check_leaks);

	str = NULL;
	while ((parse = get_next_line(fd)) != NULL)
		str = ft_strjoin(str, parse);
	param.map = ft_split(str, '\n');
	free(str);


	i = 0;
	param.all_coins = 0;
	while (param.map[i])
	{
		j = 0;
		while (param.map[i][j])
		{
			if (param.map[i][j] == 'C')
				param.all_coins += 1;
			j++;
		}
		i++;
	}
///////////////////////////////


	param.col = ft_strlen(param.map[0]);
	param.row = 0;
	i = 0;
	while (i < 4)
	{
		param.kflag[i] = 0;
		i++;
	}
	param.score = 0;
	param.goal = 0;
	param.walk = 0;
	while (param.map[param.row])
		param.row++;
	param.mlx = mlx_init();
	init_digit(&param);
	init_coins(&param);
	init_move(&param);
	param.ground = mlx_xpm_file_to_image(param.mlx, "imgs/ground.xpm", &param.width, &param.height);
	param.obstacle = mlx_xpm_file_to_image(param.mlx, "imgs/obstacle.xpm", &param.width, &param.height);
	param.escape = mlx_xpm_file_to_image(param.mlx, "imgs/escape.xpm", &param.width, &param.height);
	param.win = mlx_new_window(param.mlx, (param.width) * param.col, (param.height) * param.row, "so_long");
	param.x = 0;
	param.y = 0;
	init_map(&param);
	mlx_hook(param.win, KEY_PRESS, 0, &key_press, &param);
	mlx_hook(param.win, PRESS_RED_BUTTON, 0, &ft_close, &param);
	mlx_loop_hook(param.mlx, &draw_map, &param);
	mlx_loop(param.mlx);


/////////////////////////////////
	i = 0;
	while (param.map[i])
	{
		free(param.map[i]);
		i++;
	}
	free(param.map);
	close(fd);
}
