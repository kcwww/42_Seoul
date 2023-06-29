/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:43:28 by chanwoki          #+#    #+#             */
/*   Updated: 2023/06/29 17:13:32 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_info	*info;

	if (check_argcs(argc, argv) == FALSE)
		return (0);
	info = set_struct(argc, argv);
	return (0);
}
