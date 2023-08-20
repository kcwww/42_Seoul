/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_even.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:50:19 by chanwoki          #+#    #+#             */
/*   Updated: 2023/08/20 16:18:22 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	even_philo(t_info *info, t_philo *philo)
{
	if (check_philo(info, philo))
		return (TRUE);
	eat(info, philo);
	if (check_philo(info, philo))
		return (TRUE);
	sleep_philo(info, philo);
	if (check_philo(info, philo))
		return (TRUE);
	thinking(info, philo);
	return (FALSE);
}

int	odd_philo(t_info *info, t_philo *philo)
{
	if (check_philo(info, philo))
		return (TRUE);
	sleep_philo(info, philo);
	if (check_philo(info, philo))
		return (TRUE);
	thinking(info, philo);
	if (check_philo(info, philo))
		return (TRUE);
	eat(info, philo);
	return (FALSE);
}

void	*act_even(void *ptr)
{
	t_info	*info;
	t_philo	*philo;

	philo = (t_philo *)ptr;
	info = philo->info;
	while (TRUE)
	{
		if (philo->lfork % 2 == 0)
		{
			if (even_philo(info, philo))
				break ;
		}
		else
		{
			if (odd_philo(info, philo))
				break ;
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
