/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:09:39 by chanwoki          #+#    #+#             */
/*   Updated: 2023/08/20 16:10:18 by chanwoki         ###   ########.fr       */
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

int	check_philo(t_info *info, t_philo *philo)
{
	if (check_die(info) || philo->num_of_eat == info->num_of_must_eat || \
		info->num_of_must_eat == 0 || check_philo_die(info, philo))
		return (TRUE);
	return (FALSE);
}
