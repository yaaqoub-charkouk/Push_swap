#include "../push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	if (ac < 2)
		exit(0);
	else
	{
		main_parsing(av, ac, &stack_a);
	}
	return (0);
}