/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:24:00 by chanwoki          #+#    #+#             */
/*   Updated: 2023/08/24 21:48:16 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_die(t_info *info)
{
	int	flag;

	flag = FALSE;
	pthread_mutex_lock(&info->die);
	if (info->live == DEAD)
		flag = TRUE;
	pthread_mutex_unlock(&info->die);
	return (flag);
}

void	philo_start(t_philo *philo)
{
	t_info	*info;

	info = philo[0].info;
	if (info->num_of_must_eat == 0)
		return ;
	if (info->num_of_philo % 2 == 0)
		philo_even(philo);
	else
		philo_odd(philo);
}
