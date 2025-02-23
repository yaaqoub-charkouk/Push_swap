#include "../push_swap.h"

void	from_b_to_a(t_stack **a, t_stack **b)
{
	t_stack *max;
	int	size;
	int	index;

	while (*b)
	{
		size = ft_stack_size(*b) / 2;
		max = get_max_node(*b);
		index = max->index;
		if (max_node_index(*b, index) < size)
		{
				while ((*b)->index != index)
					rb(b);
		}
		else
		{
			while ((*b)->index != index)
					rrb(b);
		}
		pa(a, b);
	}
}

void	sort_larger_stack(t_stack **a, t_stack **b)
{
	int min;
	int max;

	min = 0;
	max = ft_stack_size(*a) * 0.048 + 10;
	while (*a)
	{
		if ((*a)->index >= min && (*a)->index <= max)
		{
			pb(a, b);
			min++;
			max++;
		}
		else if ((*a)->index > max)
			ra(a);
		else if ((*a)->index < max)
		{
			pb(a, b);
			rb(b);
			min++;
			max++;
		}
	}
	from_b_to_a(a, b);
}
