/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 12:48:46 by chanwoki          #+#    #+#             */
/*   Updated: 2022/12/01 20:40:01 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *buf)
{
	int		len;
	char	*read_str;

	len = 1;
	read_str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (read_str == 0)
		return (0);
	while (!ft_strchr(buf, '\n') && len != 0)
	{
		len = read(fd, read_str, BUFFER_SIZE);
		if (len == -1)
		{
			free(read_str);
			return (0);
		}
		read_str[len] = 0;
		if (ft_strlen(buf) >= len) // && len == 0
		{
			if (ft_strlen(read_str) > 0)
				ft_strjoin(buf, read_str);
			free(read_str);
			// buffer가 여기서 못 받음
			return (buf);
		}
		buf = ft_strjoin(buf, read_str);
	}
	free(read_str);
	return (buf);
}
// get_idx_nl
// -1 or idx_nl
char	*buf_to_line(char *buf)
{
	int		i;
	char	*return_line;

	if (buf == 0)
		return (0);
	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		i++;
	return_line = (char *)malloc(sizeof(char) * (i + 1));
	if (return_line == 0)
		return (0);
	ft_strlcpy(return_line, buf, i + 1);
	return (return_line);
}

char	*next_buf(char *buf)
{
	int		i;
	char	*left_buf;

	if (buf == 0)
		return (0);
	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		i++;
	left_buf = (char *)malloc(sizeof(char) * (ft_strlen(buf) - i + 1));
	if (left_buf == 0)
	{
		free(buf);
		return (0);
	}
	ft_strlcpy(left_buf, (buf + i), ft_strlen(buf) - i + 1);
	free(buf);
	return (left_buf);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buf;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (0);
	buf = ft_read(fd, buf);
	line = buf_to_line(buf);
	buf = next_buf(buf);
	return (line);
} // strdup
