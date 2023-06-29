/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:44:55 by chanwoki          #+#    #+#             */
/*   Updated: 2023/06/29 17:57:56 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# define TRUE 1
# define FALSE 0
# define DEAD 1
# define HOLD 1
# define LAY 0

typedef int	t_bool;

typedef struct s_info {
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_must_eat;
	long long		start;
	int				live;
	pthread_t		*thread;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	pthread_mutex_t	die;
}	t_info;

typedef struct s_philo {
	int				id;
	int				left_fork;
	int				right_fork;
	int				num_of_eat;
	long long		last_eat;
}	t_philo;


char			**ft_split(char const *s, char c);
t_bool			ft_isdigit(char c);
t_bool			check_argcs(int argc, char **argv);
int				ft_atoi(char *str);
void			ft_usleep(int msec, long long time);
long long		get_time(long long start);
t_info			*set_struct(int argc, char **argv);
void			set_mutex(t_info *info);

#endif
