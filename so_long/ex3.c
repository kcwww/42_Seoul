/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 16:56:38 by chanwoki          #+#    #+#             */
/*   Updated: 2023/01/29 12:59:13 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include "mlx/mlx.h"

// mlx 구조체 mlx 포인터와 생성할 win 포인터를 가지고 있다.
typedef struct	s_vars {
	void		*mlx;
	void		*win;
}				t_vars;

// esc key press event
int	key_hook(int keycode, t_vars *vars)
{
	if(keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	main(void)
{
	t_vars	var;
	void	*img;
	void	*img2;
	void	*img3;
	void	*octo1;
	void	*octo2;
	void	*octo3;
	void	*octo4;
	int		img_width;
	int		img_height;

	var.mlx = mlx_init();
	var.win = mlx_new_window(var.mlx, 496, 496, "cw game");
	img = mlx_xpm_file_to_image(var.mlx, "imgs/ground.xpm", &img_width, &img_height);
	img2 = mlx_xpm_file_to_image(var.mlx, "imgs/obstacle.xpm", &img_width, &img_height);
	img3 = mlx_xpm_file_to_image(var.mlx, "imgs/escape.xpm", &img_width, &img_height);
	octo1 = mlx_xpm_file_to_image(var.mlx, "imgs/octo.xpm", &img_width, &img_height);
	octo2 = mlx_xpm_file_to_image(var.mlx, "imgs/octoleft.xpm", &img_width, &img_height);
	octo3 = mlx_xpm_file_to_image(var.mlx, "imgs/octoright.xpm", &img_width, &img_height);
	octo4 = mlx_xpm_file_to_image(var.mlx, "imgs/octoback.xpm", &img_width, &img_height);
    //xpm 파일을 불러와 이미지로 변환하고 img에 저장해줌
	for (int i = 0; i <= 480; i += 15)
	{
		for (int j = 0; j <= 480; j += 15)
		{
			mlx_put_image_to_window(var.mlx, var.win, img, i, j);
			if (i == 0 || i == 480 || j == 0 || j == 480)
				mlx_put_image_to_window(var.mlx, var.win, img2, i, j);
			else if ( j == 30 && i > 150 && i < 300)
				mlx_put_image_to_window(var.mlx, var.win, img2, i, j);
			else if ( i == 225 && j > 150 && j < 300)
				mlx_put_image_to_window(var.mlx, var.win, img2, i, j);
			else if ( j == 150 && i > 60 && i < 420)
				mlx_put_image_to_window(var.mlx, var.win, img2, i, j);
			else if ( i == 120 && j > 240 && j < 420)
				mlx_put_image_to_window(var.mlx, var.win, img2, i, j);
			else if ( j == 420 && i > 115 && i < 360)
				mlx_put_image_to_window(var.mlx, var.win, img2, i, j);
			else if (i == 450 && j == 450)
				mlx_put_image_to_window(var.mlx, var.win, img3, i, j);

			else if (i == 320 && j == 120)
				mlx_put_image_to_window(var.mlx, var.win, octo2, i, j);
			else if (i == 120 && j == 150)
				mlx_put_image_to_window(var.mlx, var.win, octo2, i, j);

			else if (i == 420 && j == 120)
				mlx_put_image_to_window(var.mlx, var.win, octo3, i, j);
			else if (i == 330 && j == 90)
				mlx_put_image_to_window(var.mlx, var.win, octo3, i, j);

			else if (i == 210 && j == 420)
				mlx_put_image_to_window(var.mlx, var.win, octo4, i, j);
			else if (i == 90 && j == 210)
				mlx_put_image_to_window(var.mlx, var.win, octo4, i, j);

			else if (i == 210 && j == 330)
				mlx_put_image_to_window(var.mlx, var.win, octo1, i, j);
			else if (i == 120 && j == 150)
				mlx_put_image_to_window(var.mlx, var.win, octo1, i, j);
		}
	}
    // xpm에서 이미지로 변환한 img를 화면에 (50,50)위치에 띄워줌
	mlx_key_hook(var.win, key_hook, &var); // esc key press event
	mlx_loop(var.mlx);
	return (0);
}
