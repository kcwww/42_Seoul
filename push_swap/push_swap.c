/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwookim <chanwookim@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:18:34 by chanwoki          #+#    #+#             */
/*   Updated: 2023/03/24 13:48:04 by chanwookim       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_leaks(void)
{
	system("leaks push_swap");
}

void	print_stack(char *str, t_ps *a, t_ps *b)
{
	t_deque	*s;

	s = a->head;
	if (s == NULL)
		ft_printf("------%s-----None a-------------\n", str);
	else
	{
		ft_printf("------%s------a-----------------\n", str);
		while (s)
		{
			ft_printf("stack a is %d\n", s->content);
			s = s->next;
		}
		s = a->tail;
		ft_printf("------------re a-----------------\n");
		while (s)
		{
			ft_printf("re stack a is %d\n", s->content);
			s = s->previous;
		}
	}
	s = b->head;
	if (s == NULL)
		ft_printf("-----------None b-------------\n");
	else
	{
		ft_printf("------------b-----------------\n");
		while (s)
		{
			ft_printf("stack b is %d\n", s->content);
			s = s->next;
		}
		s = b->tail;
		ft_printf("------------re b-----------------\n");
		while (s)
		{
			ft_printf("re stack b is %d\n", s->content);
			s = s->previous;
		}
	}
	ft_printf("\n\n\n");
}

int	main(int argc, char **argv)
{
	t_ps	a;
	t_ps	b;

	atexit(check_leaks);
	ft_memset(&a, 0, sizeof(t_ps));
	ft_memset(&b, 0, sizeof(t_ps));
	if (check_arg(argc, argv) == -1)
		return (-1);
	if (init_deque(argc, argv, &a) == -1)
		return (-1);
	if (check_sorting(&a) == 1)
	{
		ft_dequeclear(&a);
		return (0);
	}
	if (ft_dequesize(a.head) == 3)
		sort_three(&a, &b);
	else if (ft_dequesize(a.head) == 2)
		execute_rules("sa", &a, &b);
	else
		set_pivot(&a, &b);
	print_stack("final stack", &a, &b);
	ft_dequeclear(&a);
	ft_dequeclear(&b);
}
