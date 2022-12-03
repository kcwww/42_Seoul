/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:44:37 by chanwoki          #+#    #+#             */
/*   Updated: 2022/12/03 15:42:25 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_str(char *line, char *buf)
{
	if (line != NULL)
		free(line);
	if (buf != NULL)
		free(buf);
}

char	*ft_read(char *line, int fd)
{
	int		len;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	len = 1;
	while (len != 0 && ft_strchr(buf, '\n') == NULL)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len == -1)
		{
			free_str(line, buf);
			return (NULL);
		}
		if (len != 0)
		{
			buf[len] = 0;
			line = ft_strjoin(line, buf);
		}
	}
	free(buf);
	return (line);
}

char	*get_line(char *line)
{
	char	*g_line;
	int		len;

	len = 0;
	while (line[len] && line[len] != '\n')
		len++;
	if (line[len] == '\n')
		len++;
	g_line = (char *)malloc(sizeof(char) * (len + 1));
	if (g_line == NULL)
		return (NULL);
	ft_strlcpy(g_line, line, len + 1);
	return (g_line);
}

char	*next_line(char *line)
{
	char	*n_line;
	int		len;
	int		line_len;

	len = 0;
	line_len = ft_strlen(line);
	while (line[len] && line[len] != '\n')
		len++;
	if (line[len] == '\n')
		len++;
	if (line_len == len)
		return (NULL);
	n_line = (char *)malloc(sizeof(char) * (line_len - len + 1));
	if (n_line == NULL)
		return (NULL);
	ft_strlcpy(n_line, line + len, line_len - len + 1);
	free(line);
	return (n_line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*re;

	line = ft_read(line, fd);
	if (line == NULL)
		return (NULL);
	re = get_line(line);
	if (re == NULL)
		return (NULL);
	line = next_line(line);
	return (re);
}
