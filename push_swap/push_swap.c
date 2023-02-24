#include "push_swap.h"

void check_leaks(void)
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

int main(int argc, char **argv)
{
	t_ps	A;
	t_ps	B;
	t_deque	*lst;
	int		i;

	atexit(check_leaks);
	ft_memset(&A, 0, sizeof(t_ps));
	ft_memset(&B, 0, sizeof(t_ps));
	if (argc <= 1)
		return (-1);
	if (check_arg(argc, argv) == -1)
		return (-1);
	i = 2;
	lst = ft_dequenew(ft_atoi(argv[1]));
	A.head = lst;
	while (i < argc)
	{
		lst->next = ft_dequenew(ft_atoi(argv[i]));
		lst->next->previous = lst;
		lst = lst->next;
		i++;
	}
	A.tail = lst;

	execute_rules("pb", &A, &B);
	print_stack("pb", &A, &B);
	execute_rules("pb", &A, &B);
	print_stack("pb", &A, &B);
	execute_rules("pb", &A, &B);
	print_stack("pb", &A, &B);
	execute_rules("pb", &A, &B);
	print_stack("pb", &A, &B);
	execute_rules("pb", &A, &B);
	print_stack("pb", &A, &B);
	execute_rules("rb", &A, &B);
	print_stack("rb", &A, &B);
	execute_rules("ra", &A, &B);
	print_stack("ra", &A, &B);
	execute_rules("pb", &A, &B);
	print_stack("pb", &A, &B);
	execute_rules("ss", &A, &B);
	print_stack("ss", &A, &B);
	execute_rules("rr", &A, &B);
	print_stack("rr", &A, &B);
	execute_rules("pa", &A, &B);
	print_stack("pa", &A, &B);
	execute_rules("sa", &A, &B);
	print_stack("sa", &A, &B);
	execute_rules("sb", &A, &B);
	print_stack("sb", &A, &B);
	execute_rules("rrb", &A, &B);
	print_stack("rrb", &A, &B);
	execute_rules("rb", &A, &B);
	print_stack("rb", &A, &B);
	execute_rules("pa", &A, &B);
	print_stack("pa", &A, &B);
	execute_rules("pa", &A, &B);
	print_stack("pa", &A, &B);
	execute_rules("ra", &A, &B);
	print_stack("ra", &A, &B);
	execute_rules("rra", &A, &B);
	print_stack("rra", &A, &B);

	t_deque	*temp = A.head;
	ft_dequeclear(&A);
	temp = B.head;
	ft_dequeclear(&B);
}
