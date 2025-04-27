/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcw <kcw@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:30:27 by chanwoki          #+#    #+#             */
/*   Updated: 2023/09/13 19:54:12 by kcw              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_comma(char *line, char **color_info, t_config *config)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	while (line[i])
	{
		if (line[i] == ',')
			comma++;
		i++;
	}
	if (comma != 2)
	{
		color_error(1, 0, color_info, config);
		return (1);
	}
	return (0);
}

static void	set_direction(char c, t_config *config)
{
	if (c == 'N')
		config->direction = "N";
	else if (c == 'S')
		config->direction = "S";
	else if (c == 'E')
		config->direction = "E";
	else if (c == 'W')
		config->direction = "W";
}

static int	check_component(char content, t_config *config, int *flag)
{
	if (ft_strchr("01NSEW ", content) == NULL)
	{
		config->error = 1;
		return (1);
	}
	else if (ft_strchr("NSEW", content) != NULL)
	{
		if (*flag == 1)
		{
			config->error = 1;
			return (1);
		}
		*flag = 1;
		set_direction(content, config);
	}
	return (0);
}

static int	set_size(t_config *config, int height, int width, int flag)
{
	if (flag == 0)
	{
		config->error = 1;
		return (1);
	}
	config->map_height = height;
	config->map_width = width;
	if (height < 3 || width < 3)
	{
		config->error = 1;
		return (1);
	}
	else if (height > 100 || width > 100)
	{
		config->error = 1;
		return (1);
	}
	return (0);
}

int	check_maps(t_config *config, int idx, char **content)
{
	int	i;
	int	j;
	int	width;
	int	flag;

	i = idx;
	width = 0;
	flag = 0;
	while (content[i])
	{
		j = 0;
		while (content[i][j])
		{
			if (check_component(content[i][j], config, &flag))
				return (1);
			j++;
		}
		if (width < j)
			width = j;
		i++;
	}
	if (set_size(config, i - idx, width, flag))
		return (1);
	return (0);
}
