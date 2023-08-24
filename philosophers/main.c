/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:43:28 by chanwoki          #+#    #+#             */
/*   Updated: 2023/08/24 20:15:53 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free(void)
{
	system("leaks philo");
}

int	main(int argc, char **argv)
{
	t_info	*info;
	t_philo	*philo;

	atexit(ft_free);
	if (check_argcs(argc, argv) == FALSE)
		return (0);
	info = set_struct(argc, argv);
	if (info == NULL)
		return (0);
	philo = set_philo(info);
	if (info->num_of_philo == 1)
	{
		printf("%lld %d has taken a fork\n", get_time(info->start), 1);
		printf("%lld %d is died\n", get_time(info->start) + \
		info->time_to_die, 1);
		free_philo(philo);
		return (0);
	}
	philo_start(philo);
	free_philo(philo);
	return (0);
}
