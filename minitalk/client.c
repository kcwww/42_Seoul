/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:14:59 by chanwoki          #+#    #+#             */
/*   Updated: 2023/02/25 21:09:05 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit(pid_t pid, char *str)
{
	int		i;
	int		j;
	char	bits;
	int		len;

	len = ft_strlen(str);
	i = 0;
	bits = 0;
	while (str[i])
	{
		j = 0;
		while (j < 8)
		{
			bits = str[i] >> (7 - j);
			j++;
			if ((bits & 1) == 0)
				kill(pid, SIGUSR1);
			else if ((bits & 1) == 1)
				kill(pid, SIGUSR2);
			usleep(125);
		}
		i++;
	}
}

int	send_sig(pid_t pid, char *input)
{
	char	*str;

	str = ft_strjoin(input, "\n");
	if (str == NULL)
		return (-1);
	send_bit(pid, str);
	free(str);
	return (0);
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	int					e;

	if (argc != 3)
	{
		ft_printf("Wrong Arguments.\n");
		exit(1);
	}
	e = 0;
	while (argv[1][e])
	{
		if (ft_isdigit(argv[1][e]) == 0)
		{
			ft_printf("Wrong Arguments.\n");
			exit(1);
		}
		e++;
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 100 || pid > 99999)
	{
		ft_printf("Wrong Arguments.\n");
		exit(1);
	}

	e = send_sig(pid, argv[2]);
	if (e == -1)
		return (-1);
	exit(0);
}
