#include "../push_swap.h"

int	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	first = *stack;
	*stack = (*stack)->next;
	last = ft_lstlast(*stack);
	last->next = first;
	first->next = NULL;
	return (1);
}

void	ra(t_stack **stack_a)
{
	if (rotate(stack_a))
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack **stack_b)
{
	if (rotate(stack_b))
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}