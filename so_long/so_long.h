/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 13:39:34 by chanwoki          #+#    #+#             */
/*   Updated: 2023/01/30 19:40:17 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define KEY_ESC			53
# define KEY_W				13
# define KEY_S				1
# define KEY_A				0
# define KEY_D				2
# define KEY_PRESS			2
# define KEY_RELEASE		3
# define PRESS_RED_BUTTON	17

typedef struct s_digit
{
	void	*zero;
	void	*one;
	void	*two;
	void	*three;
	void	*four;
	void	*five;
	void	*six;
	void	*seven;
	void	*eight;
	void	*nine;
}	t_digit;

typedef struct s_coin
{
	void	*coin1;
	void	*coin2;
	void	*coin3;
	void	*coin4;
}	t_coin;

typedef struct s_move
{
	void	*player;
	void	*front1;
	void	*front2;
	void	*front3;
	void	*front4;
	void	*front5;
	void	*front6;
	void	*back1;
	void	*back2;
	void	*back3;
	void	*back4;
	void	*back5;
	void	*back6;
	void	*back7;
	void	*left1;
	void	*left2;
	void	*left3;
	void	*left4;
	void	*left5;
	void	*left6;
	void	*left7;
	void	*right1;
	void	*right2;
	void	*right3;
	void	*right4;
	void	*right5;
	void	*right6;
	void	*right7;
}	t_move;

typedef struct s_octo
{
	void	*octo1;
	void	*octo2;
	void	*octoleft1;
	void	*octoleft2;
	void	*octoright1;
	void	*octoright2;
	void	*octoback1;
	void	*octoback2;
}	t_octo;


typedef struct s_param
{
	void	*mlx;
	void	*win;
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
	int		all_coins;
	int		walk;
	int		goal;
	int		kflag[4];
	char	**map;
	t_digit	digit;
	t_coin	coin;
	t_move	move;
	t_octo	octo;
}	t_param;

#endif
