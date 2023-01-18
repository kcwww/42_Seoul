#include "push_swap.h"

void check_leaks(void)
{
	system("leaks push_swap");
}

int main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*list;
	t_list	*stack_b = NULL;
	int		i;

	atexit(check_leaks);

	if (argc <= 1)
		return (0);
	i = 2;
	list = ft_lstnew(ft_atoi(argv[1]));
	stack_a = list;
	while (i < argc)
	{
		list->next = ft_lstnew(ft_atoi(argv[i]));
		list = list->next;
		i++;
	}

	execute_rules("pb", &stack_a, &stack_b);
	execute_rules("pb", &stack_a, &stack_b);
	execute_rules("pb", &stack_a, &stack_b);
	execute_rules("rb", &stack_a, &stack_b);
	execute_rules("pa", &stack_a, &stack_b);
	execute_rules("rra", &stack_a, &stack_b);

	ft_printf("done\n");

	t_list	*temp;
	temp = stack_a;
	while (stack_a)
	{
		ft_printf("stack_a is %d\n", stack_a->content);
		stack_a = stack_a->next;
	}
	ft_lstclear(&temp);
	temp = stack_b;
	while (stack_b)
	{
		ft_printf("stack_b is %d\n", stack_b->content);
		stack_b = stack_b->next;
	}
	ft_lstclear(&temp);
}
