/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:44:55 by chanwoki          #+#    #+#             */
/*   Updated: 2023/08/24 03:35:08 by chanwoki         ###   ########.fr       */
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
	pthread_mutex_t	*mfork;
	pthread_mutex_t	print;
	pthread_mutex_t	die;
}	t_info;

typedef struct s_philo {
	int				num_of_eat;
	int				lfork;
	int				rfork;
	long long		last_eat;
	t_info			*info;
}	t_philo;

char			**ft_split(char const *s, char c);
t_bool			ft_isdigit(char c);
t_bool			check_argcs(int argc, char **argv);
int				ft_atoi(char *str);
void			ft_usleep(int msec);
long long		get_time(long long start);
t_info			*set_struct(int argc, char **argv);
void			set_mutex(t_info *info);
void			free_philo(t_philo *philo);
void			philo_start(t_philo *philo);
void			philo_even(t_philo *philo);
void			philo_odd(t_philo *philo);
int				check_die(t_info *info);
void			eat(t_info *info, t_philo *philo);
void			sleep_philo(t_info *info, t_philo *philo);
void			thinking(t_info *info, t_philo *philo);
t_philo			*set_philo(t_info *info);
int				ft_strcmp(char *s1, char *s2);
void			print_mutex(t_info *info, char *str, int num);
int				check_philo_die(t_info *info, t_philo *philo);
int				check_philo(t_info *info, t_philo *philo);

#endif
