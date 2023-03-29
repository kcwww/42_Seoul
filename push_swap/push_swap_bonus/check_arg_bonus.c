/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwookim <chanwookim@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:10:00 by chanwoki          #+#    #+#             */
/*   Updated: 2023/03/30 01:41:50 by chanwookim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	check_int(const char *str)
{
	int			i;
	long long	minus;
	long long	result;

	i = 0;
	minus = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		minus = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	result = result * minus;
	if (result > 2147483647 || result < -2147483648)
		return (-1);
	return (1);
}

static int	check_dup(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i + 1 < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_num(int argc, char **argv)
{
	int	i;
	int	j;
	int	re;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (j == 0 && (argv[i][j] == '-' || argv[i][j] == '+'))
				j++;
			re = ft_isdigit(argv[i][j]);
			if (re == 0)
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_arg(int argc, char **argv)
{
	int	i;
	int	re;

	re = check_num(argc, argv);
	if (re == -1)
		return (-1);
	i = 1;
	while (i < argc)
	{
		re = check_int(argv[i]);
		if (re == -1)
			return (re);
		i++;
	}
	re = check_dup(argc, argv);
	if (re == -1)
		return (re);
	return (1);
}
