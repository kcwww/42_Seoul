/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_do.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:34:33 by chanwoki          #+#    #+#             */
/*   Updated: 2023/08/25 19:43:39 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_mutex(t_info *info, char *str, int idx)
{
	pthread_mutex_lock(&info->print);
	if (check_philo(info) && ft_strcmp(str, "die") != 0)
	{
		pthread_mutex_unlock(&info->print);
		return ;
	}
	if (ft_strcmp(str, "fork") == 0)
		printf("%lld %d has taken a fork\n", get_time(info->start), idx + 1);
	else if (ft_strcmp(str, "eat") == 0)
		printf("%lld %d is eating\n", get_time(info->start), idx + 1);
	else if (ft_strcmp(str, "sleep") == 0)
		printf("%lld %d is sleeping\n", get_time(info->start), idx + 1);
	else if (ft_strcmp(str, "think") == 0)
		printf("%lld %d is thinking\n", get_time(info->start), idx + 1);
	else if (ft_strcmp(str, "die") == 0)
		printf("%lld %d died\n", get_time(info->start), idx + 1);
	else if (ft_strcmp(str, "time") == 0)
		printf("%lld time\n", get_time(info->start));
	pthread_mutex_unlock(&info->print);
}

void	set_eat(t_info *info, t_philo *philo)
{
	pthread_mutex_lock(&philo->eat_time);
	philo->last_eat = get_time(info->start);
	pthread_mutex_unlock(&philo->eat_time);
	pthread_mutex_lock(&philo->eat_num);
	philo->num_of_eat++;
	pthread_mutex_unlock(&philo->eat_num);
}

void	eat(t_info *info, t_philo *philo)
{
	int	idx;

	idx = philo->lfork;
	pthread_mutex_lock(&info->mfork[idx]);
	if (check_philo(info))
	{
		pthread_mutex_unlock(&info->mfork[idx]);
		return ;
	}
	print_mutex(info, "fork", idx);
	pthread_mutex_lock(&info->mfork[(idx + 1) % info->num_of_philo]);
	if (check_philo(info))
	{
		pthread_mutex_unlock(&info->mfork[idx]);
		pthread_mutex_unlock(&info->mfork[(idx + 1) % info->num_of_philo]);
		return ;
	}
	set_eat(info, philo);
	print_mutex(info, "fork", idx);
	print_mutex(info, "eat", idx);
	ft_usleep(info, info->time_to_eat);
	pthread_mutex_unlock(&info->mfork[idx]);
	pthread_mutex_unlock(&info->mfork[(idx + 1) % info->num_of_philo]);
}

void	sleep_philo(t_info *info, t_philo *philo)
{
	int	idx;

	idx = philo->lfork;
	print_mutex(info, "sleep", idx);
	ft_usleep(info, info->time_to_sleep);
}

void	thinking(t_info *info, t_philo *philo)
{
	int	idx;

	idx = philo->lfork;
	print_mutex(info, "think", idx);
}
