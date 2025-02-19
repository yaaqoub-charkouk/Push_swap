#include "../push_swap.h"

int	swap(t_stack **stack)
{
	int tmp;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	tmp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = tmp;
	return (1);
}

void	sa(t_stack **stack_a)
{
	if (swap(stack_a))
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack **stack_b)
{
	if (swap(stack_b))
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}
