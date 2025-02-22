/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 08:57:18 by ycharkou          #+#    #+#             */
/*   Updated: 2025/02/22 18:29:41 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void	free_and_exit(t_stack **a, char **numbers)
// {
// 	ft_error(2);
// 	if (!numbers)
// 		ft_free_matrix(numbers);
// 	ft_stack_clear(a);
// 	exit(EXIT_FAILURE);
// }

void	free_and_exit(t_stack **a, char **numbers)
{
	ft_error(2);
	if (numbers)
		ft_free_matrix(numbers);
	if (a && *a)
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

t_stack	*get_min_node(t_stack *stack)
{
	int	min;

	min = get_min(stack);
	while (stack)
	{
		if (stack->content == min)
			return (stack);
		stack = stack->next;
	}
	return (stack);
}

t_stack	*get_max_node(t_stack *stack)
{
	int	max;

	max = get_max(stack);
	while (stack)
	{
		if (stack->content == max)
			return (stack);
		stack = stack->next;
	}
	return (stack);
}
