/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:43:28 by chanwoki          #+#    #+#             */
/*   Updated: 2023/07/08 15:26:44 by chanwoki         ###   ########.fr       */
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
	philo = set_philo(info);
	philo_start(philo);
	free_philo(philo);
	return (0);
}
