#include "../push_swap.h"

int	reverse_rotate(t_stack **stack)
{
	t_stack	*before_last;
	t_stack	*last;
	if (!stack || !*stack || !(*stack)->next)
		return (0);
	before_last = ft_lst_before_last(*stack);
	last = ft_lstlast(*stack);
	before_last->next = NULL;
	last->next = *stack;
	*stack = last;
	return (1);
}

void	rra(t_stack **stack_a)
{
	if (reverse_rotate(stack_a))
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack **stack_b)
{
	if (reverse_rotate(stack_b))
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}