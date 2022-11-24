/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:37:20 by chanwoki          #+#    #+#             */
/*   Updated: 2022/11/15 15:32:05 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static unsigned int	check_len(unsigned int n)
{
	unsigned int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		len++;
		n /= 16;
	}
	return (len);
}

char	*ft_itoahex(unsigned int n, int i)
{
	int				len;
	unsigned int	num;
	char			*re;
	char			*hex;

	if (i == 1)
		hex = "0123456789abcdef";
	else if (i == 2)
		hex = "0123456789ABCDEF";
	len = check_len(n);
	num = n;
	n = 0;
	re = (char *)malloc(sizeof(char) * (len + 1));
	if (re == 0)
		return (0);
	re[len] = 0;
	while (len-- > n)
	{
		re[len] = hex[(num % 16)];
		num /= 16;
	}
	return (re);
}

int main()
{
	printf("%s\n",ft_itoahex(-123, 1));
}
