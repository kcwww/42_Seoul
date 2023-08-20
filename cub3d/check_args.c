/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:55:30 by chanwoki          #+#    #+#             */
/*   Updated: 2023/08/20 17:23:00 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_args(int args, char **argv)
{
	int	i;
	int	len;

	if (args != 2)
	{
		printf("Error : Input Only One File\n");
		return (0);
	}
	len = ft_strlen(argv[1]);
	if (len < 5)
	{
		printf("Error : Wrong File Name\n");
		return (0);
	}
	i = 0;
	while (argv[1][i])
		i++;
	i -= 4;
	if (i <= 0)
	{
		printf("Error : Wrong File Name\n");
		return (0);
	}
	if (ft_isalpha_isdigit(argv[1][i - 1]) == 0)
	{
		printf("Error : Wrong File Name\n");
		return (0);
	}
	if (ft_strcmp(&argv[1][i], ".cub") != 0)
	{
		printf("Error : Wrong File Extension\n");
		return (0);
	} else
		return (1);
}
