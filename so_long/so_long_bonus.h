/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 13:39:34 by chanwoki          #+#    #+#             */
/*   Updated: 2023/02/12 16:16:00 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include "mlx/mlx.h"
# include <stdio.h>
# include "libft/libft.h"
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# define KEY_ESC			53
# define KEY_W				13
# define KEY_S				1
# define KEY_A				0
# define KEY_D				2
# define KEY_PRESS			2
# define KEY_RELEASE		3
# define PRESS_RED_BUTTON	17

typedef struct s_dfs
{
	int	x;
	int	y;
	int	flag;
	int	coin;
	int	map_coin;
	int	**visit;
}	t_dfs;

typedef struct s_idx
{
	int	x;
	int	y;
	int	i;
	int	p;
	int	q;
	int	move[4][4];
}	t_idx;

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
	int		octos;
	int		*octo_flag;
	int		*octo_x;
	int		*octo_y;
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
	void	*now;
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
	char	**map;
	t_digit	digit;
	t_coin	coin;
	t_move	move;
	t_octo	octo;
}	t_param;

void	draw_digit(char c, t_param *param, float x_w);
void	draw_walk(t_param *param);
void	move_octo_y(t_param *param, int i);
void	move_octo_x(t_param *param, int i);
void	move_octo(t_param *param);
void	init_map(t_param *param);
void	init_coins(t_param *param);
void	init_move(t_param *param);
void	init_player(t_param *param);
void	init_map(t_param *param);
void	init_digit(t_param *param);
void	init_octo(t_param *param);
int		check_arg(int argc, char **argv);
void	free_map(t_param *param);
int		is_map_square(char **map);
int		check_map_size(char **map);
int		is_side_wall(char **map);
int		check_component(char **map);
int		check_clear(char **map);
int		key_press(int keycode, t_param *param);
void	check_wall_d(t_param *p, int check);
void	check_wall_w(t_param *p, int check);
void	check_wall_a(t_param *p, int check);
void	check_wall_s(t_param *p, int check);
void	press_w(t_param *p, int *time);
void	press_a(t_param *p, int *time);
void	press_s(t_param *p, int *time);
void	press_d(t_param *p, int *time);
void	draw_octo(t_param *param);
void	draw_coins(t_param *p, int *time);
void	draw_component(t_param *p, int *time);
int		draw_map(t_param *p);
void	dead_check(t_param *param);
void	draw_octo_lr(t_param *param, int i);
void	draw_octo_fb(t_param *param, int i);
void	move_octo(t_param *param);
void	move_octo_x(t_param *p, int i);
void	move_octo_y(t_param *p, int i);
void	draw_digit(char c, t_param *p, float i);
void	draw_walk(t_param *param);
void	check_score(t_param *p);
void	init_player_fb(t_param *param);
void	init_player_lr(t_param *param);
void	set_parameter(t_param *param);
void	set_octo_x_y(t_param *param);
int		mem_octo(t_param *param);
int		map_and_error(t_param *param, int fd);
void	get_coin(t_param *param);
int		check_map_error(t_param *param);
int		get_map(t_param *param, int fd);
int		get_octo(t_param *param);
int		check_arg_file(int argc, char **argv);
int		error_one(t_param *param);
int		error_two(t_param *param);
void	draw_img(t_param *p, void *img, int x, int y);
void	draw_octo_img(t_param *p, void *img, int i);
void	*input_img(t_param *p, char *str);
char	*get_one_line(int fd);
void	free_visit(int **visit, char **map);
int		is_map_square(char **map);
int		check_arg(int argc, char **argv);
int		**init_visit(char **map);
void	move_setting(t_idx *idx);
void	dfs_clear(int x, int y, char **map, t_dfs *dfs);
int		check_clear(char **map);
void	zero_arr(int **visit, char **map);

#endif
