/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:17:37 by chanwoki          #+#    #+#             */
/*   Updated: 2022/11/19 19:22:03 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(const char *format, va_list ap)
{
	if (*format == 0)
		return (-1);
	if (*format == 'c')
		ft_putchar_fd(va_arg(ap, int), 1);
	else if (*format == 'd')
		ft_putnbr_fd(va_arg(ap, int), 1);
	else if (*format == 'x')
		ft_printhex(va_arg(ap, int), 1);
	else if (*format == 'X')
		ft_printhex(va_arg(ap, int), 2);
	else if (*format == 's')
		ft_putstr_fd(va_arg(ap, char *), 1);
	else if (*format == 'p')
		ft_printpointer(va_arg(ap, void *));
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, format);
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			if(check_format(++format, ap) == -1)
			{
				va_end(ap);
				return (-1);
			}
		}
		else
			write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (1);
}

#include <stdio.h>

int main()
{
	int	num;
	char	*str;

	str = 0;
	num = printf("%s",str);
	printf("%d\n",num);
}
