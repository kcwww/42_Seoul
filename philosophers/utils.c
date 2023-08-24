/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:57:52 by chanwoki          #+#    #+#             */
/*   Updated: 2023/08/24 21:12:09 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	idx;

	idx = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[idx] && s2[idx])
	{
		if (s1[idx] != s2[idx])
			return ((unsigned char)s1[idx] - (unsigned char)s2[idx]);
		idx++;
	}
	return ((unsigned char)s1[idx] - (unsigned char)s2[idx]);
}

void	ft_usleep(t_info *info, t_philo *philo, int msec)
{
	struct timeval	tv;
	long long		end;
	long long		start;

	gettimeofday(&tv, NULL);
	start = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	end = start;
	while (1)
	{
		usleep(100);
		gettimeofday(&tv, NULL);
		end = tv.tv_sec * 1000 + tv.tv_usec / 1000;
		if (check_philo(info, philo))
			break ;
		if (end - start >= msec)
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
