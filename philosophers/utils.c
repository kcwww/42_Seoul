/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:57:52 by chanwoki          #+#    #+#             */
/*   Updated: 2023/06/25 20:20:59 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(int msec, long long time)
{
	struct timeval	tv;
	long long		end;

	end = 0;
	while (1)
	{
		usleep(100);
		gettimeofday(&tv, NULL);
		end = tv.tv_sec * 1000 + tv.tv_usec / 1000;
		if (end - time >= msec)
			break ;
	}
}

t_bool	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	return (FALSE);
}

int	ft_atoi(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}
