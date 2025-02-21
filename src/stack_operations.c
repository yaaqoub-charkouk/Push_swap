#include "../push_swap.h"

void	store_in_stack(t_stack **stack, int value)
{
	t_stack *new_node;

	new_node = ft_lstnew(value);
	if (!new_node)
		return ;
	ft_lstadd_back(stack, new_node);
}

int	is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);	
}

void	sort_three(t_stack *stack)
{
	int	max;

	max = get_max(stack);
	if (max == stack->content)
		ra(&stack);
	if (max == stack->next->content)
		rra(&stack);
	if (stack->content > stack->next->content)
		sa(&stack);
}

void	sort_four(t_stack *a, t_stack *b)
{
	int	min;

	min = get_min(a);
	if (a->next->content == min)
		ra(&a);
	else if (a->next->next->content == min)
	{
		rra(&a);
		rra(&a);
	}
	else if (a->next->next->next->content == min)
		rra(&a);
	if (!is_sorted(a))
	{
		pb(&a, &b);
		sort_three(a);
		pa(&a, &b);
	}
}


void	sort_stack(t_stack *a, t_stack *b)
{
	int	size;

	size = ft_stack_size(a);
	if (size == 2)
		sa(&a);
	if (size == 3)
		sort_three(a);
	if (size == 4)
		sort_four(a, b);
}