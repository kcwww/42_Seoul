/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:09:39 by chanwoki          #+#    #+#             */
/*   Updated: 2023/08/24 21:26:43 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_philo_die(t_info *info, t_philo *philo)
{
	int	flag;

	flag = FALSE;
	if (get_time(info->start) - philo->last_eat > info->time_to_die)
	{
		pthread_mutex_lock(&info->die);
		print_mutex(info, "die", philo->lfork);
		info->live = DEAD;
		pthread_mutex_unlock(&info->die);
		flag = TRUE;
	}
	return (flag);
}

int	check_eat(t_info *info, t_philo *philo)
{
	int	flag;
	int	i;

	i = 0;
	flag = FALSE;
	while (i < info->num_of_philo)
	{
		if (philo[i].num_of_eat < info->num_of_must_eat)
			break ;
		i++;
	}
	if (i == info->num_of_philo || info->num_of_must_eat == 0)
	{
		pthread_mutex_lock(&info->die);
		info->live = DEAD;
		pthread_mutex_unlock(&info->die);
		flag = TRUE;
	}
	return (flag);
}

int	check_philo(t_info *info)
{
	pthread_mutex_lock(&info->die);
	if (info->live == DEAD)
	{
		pthread_mutex_unlock(&info->die);
		return (TRUE);
	}
	pthread_mutex_unlock(&info->die);
	return (FALSE);
}
