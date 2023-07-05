/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:24:00 by chanwoki          #+#    #+#             */
/*   Updated: 2023/07/05 15:47:45 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*make_philo(t_info *info)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo) * info->num_of_philo);
	memset(philo, 0, sizeof(t_philo) * info->num_of_philo);
	return (philo);
}

void	philo_start(t_info *info)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = make_philo(info);
	info->philo = philo;
	while (i < info->num_of_philo)
	{
		philo->id = i + 1;
		philo->num_of_eat = 0;
		philo->last_eat = info->start;
		i++;
		if (i == info->num_of_philo)
			break ;
		philo->next = make_philo(info);
		philo = philo->next;
	}
	philo->next = info->philo;
}
