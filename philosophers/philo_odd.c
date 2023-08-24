/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_odd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:50:32 by chanwoki          #+#    #+#             */
/*   Updated: 2023/08/24 21:33:50 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	odd_philo(t_info *info, t_philo *philo)
{
	if (check_philo(info))
		return (TRUE);
	eat(info, philo);
	if (check_philo(info))
		return (TRUE);
	sleep_philo(info, philo);
	usleep(200);
	if (check_philo(info))
		return (TRUE);
	thinking(info, philo);
	return (FALSE);
}

static int	even_philo(t_info *info, t_philo *philo)
{
	if (check_philo(info))
		return (TRUE);
	sleep_philo(info, philo);
	if (check_philo(info))
		return (TRUE);
	thinking(info, philo);
	if (check_philo(info))
		return (TRUE);
	eat(info, philo);
	return (FALSE);
}

void	*act_odd(void *ptr)
{
	t_info	*info;
	t_philo	*philo;

	philo = (t_philo *)ptr;
	info = philo->info;
	while (TRUE)
	{
		if (philo->lfork % 2 == 0)
		{
			if (odd_philo(info, philo))
				break ;
		}
		else
		{
			if (even_philo(info, philo))
				break ;
		}
	}
	return (NULL);
}

void	monitoring(t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	while (TRUE)
	{
		if (i == info->num_of_philo)
			i = 0;
		if (check_philo_die(info, &philo[i]))
			break ;
		if (info->num_of_must_eat != (-1) && check_eat(info, philo))
			break ;
		i++;
	}
	return ;
}

void	philo_odd(t_philo *philo)
{
	t_info	*info;
	int		i;

	info = philo[0].info;
	i = 0;
	while (i < info->num_of_philo)
	{
		pthread_create(&info->thread[i], NULL, act_odd, &philo[i]);
		i++;
	}
	usleep(200);
	monitoring(info, philo);
	i = 0;
	while (i < info->num_of_philo)
	{
		pthread_join(info->thread[i], NULL);
		i++;
	}
	return ;
}
