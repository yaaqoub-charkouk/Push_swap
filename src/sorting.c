/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 08:55:59 by ycharkou          #+#    #+#             */
/*   Updated: 2025/02/22 19:28:32 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_stack **stack)
{
	int	max;

	max = get_max((*stack));
	if (max == (*stack)->content)
		ra(stack);
	else if (max == (*stack)->next->content)
		rra(stack);
	if ((*stack)->content > (*stack)->next->content)
		sa(stack);
}

void	sort_four(t_stack **a, t_stack **b)
{
	int	min;

	min = get_min(*a);
	if ((*a)->next->content == min)
		ra(a);
	else if ((*a)->next->next->content == min)
	{
		rra(a);
		rra(a);
	}
	else if ((*a)->next->next->next->content == min)
		rra(a);
	if (!is_sorted(*a))
	{
		pb(a, b);
		sort_three(a);
		pa(a, b);
	}
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	min;

	min = get_min(*a);
	if ((*a)->next->content == min)
		ra(a);
	else if ((*a)->next->next->content == min)
	{
		ra(a);
		ra(a);
	}
	else if ((*a)->next->next->next->content == min)
	{
		rra(a);
		rra(a);
	}
	else if ((*a)->next->next->next->next->content == min)
		rra(a);
	if (!is_sorted(*a))
	{
		pb(a, b);
		sort_four(a, b);
		pa(a, b);
	}
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_stack_size(*a);
	if (size == 2)
		sa(a);
	if (size == 3)
		sort_three(a);
	if (size == 4)
		sort_four(a, b);
	if (size == 5)
		sort_five(a, b);
	else
	{
		indexing(a);
		sort_larger_stack(a, b);
	}
}
