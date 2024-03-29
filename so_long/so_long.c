/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 13:38:44 by chanwoki          #+#    #+#             */
/*   Updated: 2023/02/10 16:51:07 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_close(void)
{
	exit (0);
	return (0);
}

int	check_arg_file(int argc, char **argv)
{
	int	fd;

	if (check_arg(argc, argv) == -1)
	{
		printf("Error\nInvalid format\n");
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("Error\n%s\n", strerror(errno));
		return (-1);
	}
	return (fd);
}

void	draw_img(t_param *p, void *img, int x, int y)
{
	mlx_put_image_to_window(p->mlx, p->win, img, x, y);
}

int	main(int argc, char **argv)
{
	t_param	param;
	int		fd;

	fd = check_arg_file(argc, argv);
	if (fd == -1)
		return (-1);
	if (map_and_error(&param, fd) == -1)
		return (-1);
	param.mlx = mlx_init();
	get_coin(&param);
	set_parameter(&param);
	init_map(&param);
	mlx_hook(param.win, KEY_PRESS, 0, &key_press, &param);
	mlx_hook(param.win, PRESS_RED_BUTTON, 0, &ft_close, &param);
	mlx_loop_hook(param.mlx, &draw_map, &param);
	mlx_loop(param.mlx);
	free_map(&param);
	close(fd);
}
