/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:15:02 by chanwoki          #+#    #+#             */
/*   Updated: 2023/03/10 16:00:05 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	get_sig(int sig)
{
	static char	letter;
	static int	bit;

	if (sig == SIGUSR1)
	{
		letter |= 0;
		if (bit < 7)
			letter <<= 1;
	}
	else if (sig == SIGUSR2)
	{
		letter |= 1;
		if (bit < 7)
			letter <<= 1;
	}
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", letter);
		bit = 0;
		letter = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	action;

	pid = getpid();
	action.sa_flags = SA_SIGINFO;
	action.sa_handler = get_sig;
	sigemptyset(&action.sa_mask);
	ft_printf("PID : %d\n", pid);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
	return (0);
}
