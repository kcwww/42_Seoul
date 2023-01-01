#include "push_swap.h"

int main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*a_list;
	char	*re;
	//t_stack	*stack_b;
	int		i;

	if (argc <= 1)
		return (0);
	i = 2;
	a_list = ft_lstnew(ft_atoi(argv[1]));
	stack_a = a_list;
	while (i < argc)
	{
		a_list->next = ft_lstnew(ft_atoi(argv[i]));
		a_list = a_list->next;
		i++;
	}

	t_list	*temp;
	re = "ra";

	if (ft_strncmp(re, "sa", 3) == 0)
	{
		temp = stack_a->next;
		stack_a->next = temp->next;
		temp->next = stack_a;
		stack_a = temp;
	}
	// else if (ft_strcmp(re, "sb") == 0)
	// {

	// }
	// else if (ft_strcmp(re, "ss") == 0)
	// {

	// }
	// else if (ft_strcmp(re, "pa") == 0)
	// {

	// }
	// else if (ft_strcmp(re, "pb") == 0)
	// {

	// }
	else if (ft_strncmp(re, "ra", 3) == 0)
	{
		a_list = ft_lstlast(stack_a);
		temp = stack_a;
		stack_a = stack_a->next;
		a_list->next = temp;
		temp->next = NULL;
	}
	// else if (ft_strcmp(re, "rb") == 0)
	// {

	// }
	// else if (ft_strcmp(re, "rr") == 0)
	// {

	// }
	// else if (ft_strcmp(re, "rra") == 0)
	// {

	// }
	// else if (ft_strcmp(re, "rrb") == 0)
	// {

	// }
	// else if (ft_strcmp(re, "rrr") == 0)
	// {

	// }
	temp = stack_a;
	while (stack_a)
	{
		ft_printf("d is %d\n", stack_a->content);
		stack_a = stack_a->next;
	}
	ft_lstclear(&temp);
	system("leaks push_swap");
}
