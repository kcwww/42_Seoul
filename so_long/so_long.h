/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 13:39:34 by chanwoki          #+#    #+#             */
/*   Updated: 2023/02/12 16:16:13 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
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

typedef struct s_coin
{
	void	*coin1;
}	t_coin;

typedef struct s_move
{
	void	*player;
	void	*back1;
	void	*left1;
	void	*right1;
}	t_move;

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
	t_coin	coin;
	t_move	move;
}	t_param;

void	init_map(t_param *param);
void	init_coins(t_param *param);
void	init_move(t_param *param);
void	init_player(t_param *param);
void	init_map(t_param *param);
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
void	press_w(t_param *p);
void	press_a(t_param *p);
void	press_s(t_param *p);
void	press_d(t_param *p);
void	draw_coins(t_param *p);
void	draw_component(t_param *p);
int		draw_map(t_param *p);
void	dead_check(t_param *param);
void	check_score(t_param *p);
void	init_player_fb(t_param *param);
void	init_player_lr(t_param *param);
void	set_parameter(t_param *param);
int		map_and_error(t_param *param, int fd);
void	get_coin(t_param *param);
int		check_map_error(t_param *param);
int		get_map(t_param *param, int fd);
int		check_arg_file(int argc, char **argv);
int		error_one(t_param *param);
int		error_two(t_param *param);
void	draw_img(t_param *p, void *img, int x, int y);
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
