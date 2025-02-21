#include "../push_swap.h"


void	print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("%d\n", stack->content);
		stack = stack->next;
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		exit(0);
	else
	{
		main_parsing(av, ac, &stack_a);
		if (is_sorted(stack_a))
			return (ft_stack_clear(&stack_a), 0);
		sort_stack(&stack_a, &stack_b);
		// if (is_sorted(stack_a))
		// 	ft_printf("yes");
		// else
		// 	ft_printf("no");
	}
	ft_free_stacks(stack_a, stack_b);
	return (0);
}