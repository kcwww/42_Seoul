/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 12:48:46 by chanwoki          #+#    #+#             */
/*   Updated: 2022/11/27 16:30:51 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*re;
	static char	*buf;
	ssize_t		len;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (0);
	re = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (re == 0)
		return (0);
	len = 1;
	while (len > 0)
	{
		len = read(fd, &re, BUFFER_SIZE);
		if (len == -1)
			break ;
		re[len] = 0;
	}

}
