/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:12:55 by chanwoki          #+#    #+#             */
/*   Updated: 2023/02/25 20:47:30 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include "ft_printf/ft_printf.h"

typedef struct s_server
{
	pid_t	client_pid;
	char	*msg;
}	t_server;

typedef struct s_client
{
	pid_t	server_pid;
	char	*msg;
}	t_client;

#endif
