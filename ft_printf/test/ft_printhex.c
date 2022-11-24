/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:17:37 by chanwoki          #+#    #+#             */
/*   Updated: 2022/11/19 19:22:03 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printhex(unsigned int num, int i)
{
	const char	*hex;

	if (i == 1)
		hex = "0123456789abcdef";
	else if (i == 2)
		hex = "0123456789ABCDEF";
	else
		return ;
	if (num > 15)
		ft_printhex(num / 16, i);
	ft_putchar_fd(hex[num % 16], 1);
}
