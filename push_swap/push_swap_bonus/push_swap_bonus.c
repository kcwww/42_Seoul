/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:51:54 by chanwookim        #+#    #+#             */
/*   Updated: 2023/03/31 15:37:42 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_str(char **line)
{
	if (line != NULL)
	{
		if (*line != NULL)
		{
			free(*line);
			*line = NULL;
		}
	}
}

static int	get_rule(char *rule, t_ps *a, t_ps *b)
{
	while (1)
	{
		rule = get_next_line(0);
		if (rule == NULL)
			return (0);
		rule = remove_newline(rule);
		if (rule == NULL)
		{
			ft_dequeclear(a);
			ft_dequeclear(b);
			return (1);
		}
		if (check_str(rule) == 1)
			execute_rules(rule, a, b);
		else
		{
			free_str(&rule);
			ft_dequeclear(a);
			ft_dequeclear(b);
			ft_printf("Error\n");
			return (1);
		}
		free_str(&rule);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_ps	a;
	t_ps	b;
	char	*rule;

	ft_memset(&a, 0, sizeof(t_ps));
	ft_memset(&b, 0, sizeof(t_ps));
	rule = NULL;
	if (argc == 1)
		return (0);
	if (check_arg(argc, argv) == -1 || init_deque(argc, argv, &a) == -1)
	{
		ft_printf("Error\n");
		return (-1);
	}
	if (get_rule(rule, &a, &b) == 1)
		return (-1);
	if (check_sorting_bonus(&a, &b) == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_dequeclear(&a);
	ft_dequeclear(&b);
}
