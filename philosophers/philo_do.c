/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_do.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:34:33 by chanwoki          #+#    #+#             */
/*   Updated: 2023/07/08 15:41:38 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_info *info, t_philo *philo)
{
	int	idx;

	idx = philo->lfork;
	pthread_mutex_lock(&info->mfork[idx]);
	pthread_mutex_lock(&info->mfork[(idx + 1) % info->num_of_philo]);
	pthread_mutex_lock(&info->print);
	printf("%lld %d has taken a fork\n", get_time(info->start), idx + 1);
	printf("%lld %d has taken a fork\n", get_time(info->start), idx + 1);
	printf("%lld %d is eating\n", get_time(info->start), idx + 1);
	pthread_mutex_unlock(&info->print);
	philo->last_eat = get_time(info->start);
	ft_usleep(info->time_to_eat);
	pthread_mutex_unlock(&info->mfork[idx]);
	pthread_mutex_unlock(&info->mfork[(idx + 1) % info->num_of_philo]);
	philo->num_of_eat++;
}
void	sleep_philo(t_info *info, t_philo *philo)
{
	int	idx;

	idx = philo->lfork;
	pthread_mutex_lock(&info->print);
	printf("%lld %d is sleeping\n", get_time(info->start), idx + 1);
	pthread_mutex_unlock(&info->print);
	ft_usleep(info->time_to_sleep);
}
void	thinking(t_info *info, t_philo *philo)
{
	int	idx;

	idx = philo->lfork;
	pthread_mutex_lock(&info->print);
	printf("%lld %d is thinking\n", get_time(info->start), idx + 1);
	pthread_mutex_unlock(&info->print);
}
