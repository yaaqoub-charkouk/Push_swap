/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 08:53:00 by ycharkou          #+#    #+#             */
/*   Updated: 2025/02/25 09:41:10 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	store_in_stack(t_stack **stack, int value)
{
	t_stack	*new_node;

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

void	ft_free_stacks(t_stack *a, t_stack *b)
{
	ft_stack_clear(&a);
	ft_stack_clear(&b);
}

int	max_node_index(t_stack *stack, int max_index)
{
	int	i;

	i = 0;
	while (stack && stack->index != max_index)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	indexing(t_stack **stack)
{
	int		i;
	t_stack	*tmp;
	t_stack	*ptr;

	ptr = *stack;
	while (ptr)
	{
		tmp = *stack;
		i = 0;
		while (tmp)
		{
			if (ptr->content > tmp->content)
				i++;
			tmp = tmp->next;
		}
		ptr->index = i;
		ptr = ptr->next;
	}
}
