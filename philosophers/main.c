/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:43:28 by chanwoki          #+#    #+#             */
/*   Updated: 2023/06/25 20:20:44 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_info	set_struct(int argc, char **argv)
{
	t_info			info;
	struct timeval	tv;

	info.num_of_philo = ft_atoi(argv[1]);
	info.time_to_die = ft_atoi(argv[2]);
	info.time_to_eat = ft_atoi(argv[3]);
	info.time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info.num_of_must_eat = ft_atoi(argv[5]);
	else
		info.num_of_must_eat = -1;
	gettimeofday(&tv, NULL);
	info.start = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (info);
}

long long	get_time(long long start)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000 - start);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (check_argcs(argc, argv) == FALSE)
		return (0);
	info = set_struct(argc, argv);
	return (0);
}
