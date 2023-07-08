/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:13:06 by chanwoki          #+#    #+#             */
/*   Updated: 2023/07/08 15:42:43 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_mutex(t_info *info)
{
	int	i;

	i = 0;
	info->mfork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* info->num_of_philo);
	pthread_mutex_init(&info->print, NULL);
	pthread_mutex_init(&info->die, NULL);
	while (i < info->num_of_philo)
	{
		pthread_mutex_init(&info->mfork[i], NULL);
		i++;
	}
	return ;
}

t_philo	*set_philo(t_info *info)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = (t_philo *)malloc(sizeof(t_philo) * info->num_of_philo);
	while (i < info->num_of_philo)
	{
		philo[i].num_of_eat = 0;
		philo[i].lfork = i;
		philo[i].rfork = (i + 1) % info->num_of_philo;
		philo[i].last_eat = info->start;
		philo[i].info = info;
		i++;
	}
	return (philo);
}

t_info	*set_struct(int argc, char **argv)
{
	t_info			*info;
	struct timeval	tv;

	info = (t_info *)malloc(sizeof(t_info));
	memset(info, 0, sizeof(t_info));
	info->num_of_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->num_of_must_eat = ft_atoi(argv[5]);
	else
		info->num_of_must_eat = -1;
	gettimeofday(&tv, NULL);
	info->start = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	info->thread = (pthread_t *)malloc(sizeof(pthread_t) * info->num_of_philo);
	set_mutex(info);
	return (info);
}

long long	get_time(long long start)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000 - start);
}
