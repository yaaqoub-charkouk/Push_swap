/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 09:48:22 by ycharkou          #+#    #+#             */
/*   Updated: 2025/02/25 09:49:06 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	push(t_stack **from, t_stack **to)
{
	t_stack	*ptr;

	if (!*from)
		return (0);
	ptr = *from;
	*from = (*from)->next;
	ptr->next = *to;
	*to = ptr;
	return (1);
}

int	swap(t_stack **stack)
{
	int	tmp;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	tmp = (*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = tmp;
	return (1);
}

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
