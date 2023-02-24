/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:10:00 by chanwoki          #+#    #+#             */
/*   Updated: 2023/02/24 18:29:48 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_dup(int argc, char **argv)
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

int	check_arg(int argc, char **argv)
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
			re = ft_isdigit(argv[i][j]);
			if (re == 0)
				return (-1);
			j++;
		}
		i++;
	}
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