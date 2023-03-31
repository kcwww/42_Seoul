/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanwoki <chanwoki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:18:34 by chanwoki          #+#    #+#             */
/*   Updated: 2023/03/31 16:49:45 by chanwoki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	select_sort(int *arr, int len)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_ps	a;
	t_ps	b;

	ft_memset(&a, 0, sizeof(t_ps));
	ft_memset(&b, 0, sizeof(t_ps));
	if (argc == 1)
		return (0);
	if (check_arg(argc, argv) == -1 || init_deque(argc, argv, &a) == -1)
	{
		ft_printf("Error\n");
		return (-1);
	}
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
	ft_dequeclear(&a);
	ft_dequeclear(&b);
}
