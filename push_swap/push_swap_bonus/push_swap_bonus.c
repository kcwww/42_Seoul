/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwookim <chanwookim@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:51:54 by chanwookim        #+#    #+#             */
/*   Updated: 2023/03/30 03:11:57 by chanwookim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	check_leaks(void)
{
	system("leaks Checker");
}

void    free_str(char **line)
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

int main(int argc, char **argv)
{
	t_ps	a;
	t_ps	b;
    char    *rule;

    atexit(check_leaks);
	ft_memset(&a, 0, sizeof(t_ps));
	ft_memset(&b, 0, sizeof(t_ps));
	if (argc == 1)
		return (0);
	if (check_arg(argc, argv) == -1 || init_deque(argc, argv, &a) == -1)
	{
		ft_printf("Error\n");
		return (-1);
	}
	while ((rule = get_next_line(0)) != NULL)
    {
        ft_printf("rule is %s", rule);
        if (check_str(rule) != NULL)
            execute_rules(rule, &a, &b);
        else
        {
            ft_printf("Error\n");
            ft_dequeclear(&a);
	        ft_dequeclear(&b);
            return (1);
        }
        free_str(&rule);
    }
    if (check_sorting_bonus(&a, &b) == 1)
        ft_printf("OK\n");
    else
        ft_printf("KO\n");
	ft_dequeclear(&a);
	ft_dequeclear(&b);
}