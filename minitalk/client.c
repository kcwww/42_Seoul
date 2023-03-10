/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:14:59 by chanwoki          #+#    #+#             */
/*   Updated: 2023/03/10 15:59:06 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_kill(pid_t pid, int sig)
{
	if (kill(pid, sig) == -1)
		ft_printf("Message send FAIL.\n");
}

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
				ft_kill(pid, SIGUSR1);
			else if ((bits & 1) == 1)
				ft_kill(pid, SIGUSR2);
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

int	check_arg(int argc, char **argv)
{
	int	e;

	if (argc != 3)
	{
		ft_printf("Wrong Arguments.\n");
		return (-1);
	}
	e = 0;
	while (argv[1][e])
	{
		if (ft_isdigit(argv[1][e]) == 0)
		{
			ft_printf("Wrong Arguments.\n");
			return (-1);
		}
		e++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	int					e;

	e = check_arg(argc, argv);
	if (e == -1)
		exit(1);
	pid = ft_atoi(argv[1]);
	if (pid <= 0 || pid > 32768)
	{
		ft_printf("Wrong Arguments.\n");
		exit(1);
	}
	e = send_sig(pid, argv[2]);
	if (e == -1)
		return (-1);
	exit(0);
}
