#include "push_swap.h"

void check_leaks(void)
{
	system("leaks push_swap");
}

int main(int argc, char **argv)
{
	t_ps	*A;
	t_ps	*B;
	t_deque	*lst;
	int		i;

	atexit(check_leaks);

	if (argc <= 1)
		return (0);
	i = 2;
	lst = ft_dequenew(ft_atoi(argv[1]));
	A->head = lst;
	while (i < argc)
	{
		lst->next = ft_dequenew(ft_atoi(argv[i]));
		lst->next->previous = lst;
		lst = lst->next;
		i++;
	}
	A->tail = lst;

	execute_rules("pb", A, B);

	t_deque	*temp = A->head;
	while (temp)
	{
		ft_printf("stack_a is %d\n", temp->content);
		temp = temp->next;
	}
	ft_dequeclear(&A);
	temp = B->head;
	while (temp)
	{
		ft_printf("stack_b is %d\n", temp->content);
		temp = temp->next;
	}
	ft_dequeclear(&B);
}
