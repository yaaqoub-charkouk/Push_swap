#include "../push_swap.h"

void	push_to_stack(t_stack **stack, int value)
{
	t_stack *new_node;

	new_node = ft_lstnew(value);
	if (!new_node)
		return ;
	ft_lstadd_front(stack, new_node);
}

void	store_in_stack(t_stack **stack, int value)
{
	t_stack *new_node;

	new_node = ft_lstnew(value);
	if (!new_node)
		return ;
	ft_lstadd_back(stack, new_node);
}
