/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:32:37 by chanwoki          #+#    #+#             */
/*   Updated: 2022/11/24 21:42:03 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printpointer(void *ptr)
{
	long long	p;
	
	p = (long long)ptr;
	if (p == 0)
		return ;
	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	ft_printhex(p, 1);
}
