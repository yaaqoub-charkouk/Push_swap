#include "../push_swap.h"

void	free_and_exit(t_stack **a, char **numbers)
{
	ft_error(2);
	if (!numbers)
		ft_free_matrix(numbers);
	ft_stack_clear(a);
	exit(EXIT_FAILURE);
}

int	get_max(t_stack *stack)
{
	int	max;

	max = stack->content;
	while (stack)
	{
		if (max < stack->content)
			max = stack->content;
		stack = stack->next;
	}
	return (max);
}

int	get_min(t_stack *stack)
{
	int	min;

	min = stack->content;
	while (stack)
	{
		if (min > stack->content)
			min = stack->content;
		stack = stack->next;
	}
	return (min);
}

void print_stack(t_stack *a)
{
	while (a)
	{
		ft_printf("hte stack is %d\n", a->content);
		a = a->next;
	}
}