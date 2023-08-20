/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_even.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:50:19 by chanwoki          #+#    #+#             */
/*   Updated: 2023/08/20 14:54:42 by chanwoki         ###   ########.fr       */
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

void	*act_even(void *ptr)
{
	t_info	*info;
	t_philo	*philo;

	philo = (t_philo *)ptr;
	info = philo->info;
	while (TRUE)
	{
		if (check_die(info) || philo->num_of_eat == info->num_of_must_eat || \
			info->num_of_must_eat == 0 || check_philo_die(info, philo))
			break ;
		if (philo->lfork % 2 == 0)
		{
			eat(info, philo);
			sleep_philo(info, philo);
			thinking(info, philo);
		}
		else
		{
			sleep_philo(info, philo);
			thinking(info, philo);
			eat(info, philo);
		}
	}
	return (NULL);
}

void	philo_even(t_philo *philo)
{
	t_info	*info;
	int		i;

	info = philo[0].info;
	i = 0;
	while (i < info->num_of_philo)
	{
		pthread_create(&info->thread[i], NULL, act_even, &philo[i]);
		i++;
	}
	i = 0;
	while (i < info->num_of_philo)
	{
		pthread_join(info->thread[i], NULL);
		i++;
	}
}
