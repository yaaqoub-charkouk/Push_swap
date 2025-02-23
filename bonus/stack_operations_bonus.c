/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 08:53:00 by ycharkou          #+#    #+#             */
/*   Updated: 2025/02/23 13:16:38 by ycharkou         ###   ########.fr       */
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
