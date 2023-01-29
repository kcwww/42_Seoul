/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 13:38:44 by chanwoki          #+#    #+#             */
/*   Updated: 2023/01/29 19:11:08 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "mlx/mlx.h"
#include "so_long.h"
#include <stdio.h>
///////////////////////////////////////////

void check_leaks(void)
{
	system("leaks so_long");
}



void	draw_map(t_param *param)
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
				mlx_put_image_to_window(param->mlx, param->win, param->coin, param->x, param->y);
			else if (param->map[i][j] == 'P')
			{
				param->start_x = param->x;
				param->start_y = param->y;
				mlx_put_image_to_window(param->mlx, param->win, param->player, param->x, param->y);
			}
			param->x += param->width;
			j++;
		}
			i++;
			param->y += param->height;
		}
	param->x = param->start_x;
	param->y = param->start_y;
}
int	key_press(int keycode, t_param *param)
// 입력에따라 좌표로 사용할 값을 증감시킴
{
	int	y_max;
	int	x_max;

	mlx_clear_window(param->mlx, param->win); //기존에 그려놨던 윈도우를 지워줌
	y_max = (param->height) * param->row;
	x_max = (param->width) * param->col;
	if (keycode == KEY_W && param->y != 0)
	{
		if (param->map[param->y / param->height - 1][param->x / param->width] != '1')
		{
			param->map[param->y / param->height][param->x / param->width] = '0';
			param->y -= param->height;
			param->walk++;
		}
	}
	else if (keycode == KEY_S && param->y < y_max - param->height)
	{
		if (param->map[param->y / param->height + 1][param->x / param->width] != '1')
		{
			param->map[param->y / param->height][param->x / param->width] = '0';
			param->y += param->height;
			param->walk++;
		}
	}
	else if (keycode == KEY_A && param->x != 0)
	{
		if (param->map[param->y / param->height][param->x / param->width - 1] != '1')
		{
			param->map[param->y / param->height][param->x / param->width] = '0';
			param->x -= param->width;
			param->walk++;
		}
	}
	else if (keycode == KEY_D && param->x < x_max - param->width)
	{
		if (param->map[param->y / param->height][param->x / param->width + 1] != '1')
		{
			param->map[param->y / param->height][param->x / param->width] = '0';
			param->x += param->width;
			param->walk++;
		}
	}
	else if (keycode == KEY_ESC)
		exit(0);
	if (param->map[param->y / param->height][param->x / param->width] == 'C')
	{
		param->score++;
		//mlx_string_put(param->mlx, param->win, 0, 0, 0xFFFFFF, "123");
	}
	else if (param->map[param->y / param->height][param->x / param->width] == 'E')
		param->goal = 1;
	param->map[param->y / param->height][param->x / param->width] = 'P';
	printf("y: %d x: %d score : %d walk : %d \n", param->y / 64, param->x / 64, param->score, param->walk);
	draw_map(param);
	if (param->goal == 1)
		exit (0);
	return (0);
}

int main()
{
	t_param	param;
	char	*parse;
	char	*str;
	int		fd;
	int		i;

	fd = open("map.txt", O_RDONLY);
	atexit(check_leaks);

	str = NULL;
	while ((parse = get_next_line(fd)) != NULL)
		str = ft_strjoin(str, parse);
	param.map = ft_split(str, '\n');
	free(str);


	i = 0;
	while (param.map[i])
	{
		printf("%s\n", param.map[i]);
		i++;
	}
///////////////////////////////


	param.col = ft_strlen(param.map[0]);
	param.row = 0;
	param.score = 0;
	param.goal = 0;
	param.walk = 0;
	while (param.map[param.row])
		param.row++;
	param.mlx = mlx_init();
	param.player = mlx_xpm_file_to_image(param.mlx, "imgs/player.xpm", &param.width, &param.height);
	param.coin = mlx_xpm_file_to_image(param.mlx, "imgs/coin.xpm", &param.width, &param.height);
	//param.octo = mlx_xpm_file_to_image(param.mlx, "imgs/octo.xpm", &param.width, &param.height);
	param.ground = mlx_xpm_file_to_image(param.mlx, "imgs/ground.xpm", &param.width, &param.height);
	param.obstacle = mlx_xpm_file_to_image(param.mlx, "imgs/obstacle.xpm", &param.width, &param.height);
	param.escape = mlx_xpm_file_to_image(param.mlx, "imgs/escape.xpm", &param.width, &param.height);
	param.win = mlx_new_window(param.mlx, (param.width) * param.col, (param.height) * param.row, "so_long");
	param.x = 0;
	param.y = 0;
	draw_map(&param);
	printf("y is %d x is %d \n", param.y, param.x);
	mlx_key_hook(param.win, &key_press, &param);
    //키보드 입력을 받아줌
	//mlx_loop_hook(param.mlx, &draw, &param);
    //이미지를 지우고 다시 그려주는 draw함수를 이벤트마다 실행해줌
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
