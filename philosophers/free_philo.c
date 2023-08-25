/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:12:52 by chanwoki          #+#    #+#             */
/*   Updated: 2023/08/25 19:22:13 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philo(t_philo *philo)
{
	t_info	*info;
	int		i;

	i = 0;
	info = philo[0].info;
	while (i < info->num_of_philo)
	{
		pthread_mutex_destroy(&info->mfork[i]);
		i++;
	}
	pthread_mutex_destroy(&info->print);
	pthread_mutex_destroy(&info->die);
	i = 0;
	while (i < info->num_of_philo)
	{
		pthread_mutex_destroy(&philo[i].eat_time);
		pthread_mutex_destroy(&philo[i].eat_num);
		i++;
	}
	free(info->mfork);
	free(info->thread);
	free(info);
	free(philo);
	return ;
}
