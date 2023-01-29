/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 13:38:44 by chanwoki          #+#    #+#             */
/*   Updated: 2023/01/29 15:31:20 by chanwoki         ###   ########.fr       */
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

int	key_press(int keycode, t_param *param)
// 입력에따라 좌표로 사용할 값을 증감시킴
{
	if (keycode == KEY_W && param->y != 0)
		param->y -= param->height;
	if (keycode == KEY_S && param->y != 480)
		param->y += param->height;
	else if (keycode == KEY_A && param->x != 0)
		param->x -= param->width;
	else if (keycode == KEY_D && param->x != 480)
		param->x += param->width;
	else if (keycode == KEY_ESC)
		exit(0);
	printf("y: %d x: %d\n", param->y, param->x);
	return (0);
}

int	draw(t_param *loc)
{
	mlx_clear_window(loc->mlx, loc->win); //기존에 그려놨던 윈도우를 지워줌
	mlx_put_image_to_window(loc->mlx, loc->win, loc->player, loc->x, loc->y);
    //새로운 좌표를 이용한 새 위치에 이미지를 그려줌
	return (0);
}
////////////////////////////////////

int main()
{
	t_param	param;
	char	*parse;
	char	*str;
	char	**map;
	int		fd;
	int		i,j;

	fd = open("map.txt", O_RDONLY);
	//map = NULL;

	atexit(check_leaks);

	while ((parse = get_next_line(fd)) != NULL)
	{
		str = ft_strjoin(str, parse);
	}
	map = ft_split(str, '\n');
	free(str);

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
///////////////////////////////


	param.col = ft_strlen(map[0]);
	param.row = 0;
	while (map[param.row])
		param.row++;
	param.mlx = mlx_init();
	param.player = mlx_xpm_file_to_image(param.mlx, "imgs/player.xpm", &param.width, &param.height);
	param.octo = mlx_xpm_file_to_image(param.mlx, "imgs/octo.xpm", &param.width, &param.height);
	param.ground = mlx_xpm_file_to_image(param.mlx, "imgs/ground.xpm", &param.width, &param.height);
	param.obstacle = mlx_xpm_file_to_image(param.mlx, "imgs/obstacle.xpm", &param.width, &param.height);
	param.escape = mlx_xpm_file_to_image(param.mlx, "imgs/escape.xpm", &param.width, &param.height);
	param.win = mlx_new_window(param.mlx, (param.width-1) * param.col, (param.height-1) * param.row, "so_long");
	param.x = 0;
	param.y = 0;
	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		param.x = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(param.mlx, param.win, param.obstacle, param.x, param.y);
			else if (map[i][j] == '0')
				mlx_put_image_to_window(param.mlx, param.win, param.ground, param.x, param.y);
			else if (map[i][j] == 'E')
				mlx_put_image_to_window(param.mlx, param.win, param.escape, param.x, param.y);
			else if (map[i][j] == 'C')
				mlx_put_image_to_window(param.mlx, param.win, param.octo, param.x, param.y);
			else if (map[i][j] == 'P')
				mlx_put_image_to_window(param.mlx, param.win, param.player, param.x, param.y);
			param.x += param.width - 1;
			j++;
		}
		i++;
		param.y += param.height - 1;
	}
	param.x = 0;
	param.y = 0;
	mlx_key_hook(param.win, &key_press, &param);
    //키보드 입력을 받아줌
	//mlx_loop_hook(param.mlx, &draw, &param);
    //이미지를 지우고 다시 그려주는 draw함수를 이벤트마다 실행해줌
	mlx_loop(param.mlx);


/////////////////////////////////
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	close(fd);
}
