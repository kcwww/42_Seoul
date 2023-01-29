/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 13:39:34 by chanwoki          #+#    #+#             */
/*   Updated: 2023/01/29 19:09:07 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define KEY_ESC			53
# define KEY_W				13
# define KEY_S				1
# define KEY_A				0
# define KEY_D				2
# define PRESS_RED_BUTTON	17

typedef struct s_param
{
	void	*mlx;
	void	*win;
	void	*player;
	//void	*octo;
	void	*coin;
	void	*obstacle;
	void	*escape;
	void	*ground;
	int		width;
	int		height;
	int		row;
	int		col;
	int		x;
	int		y;
	int		start_x;
	int		start_y;
	int		score;
	int		walk;
	int		goal;
	char	**map;
}	t_param;

// typedef struct s_param
// {
// 	void	*mlx;
// 	void	*win;
// 	void	*c;
// 	void	*g;
// 	void	*w;
// 	size_t	fd;
// 	int		x;
// 	int		y;
// 	int		wi;
// 	int		he;
// 	int		win_width;
// 	int		win_height;
// }	t_param;

#endif
