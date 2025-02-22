/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 08:52:31 by ycharkou          #+#    #+#             */
/*   Updated: 2025/02/22 17:46:27 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	leaktest(void)
{
	system("leaks -q push_swap");
}

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("%d\n", stack->content);
		stack = stack->next;
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	// atexit(leaktest);
	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (ft_error(2), 1);
	else
	{
		if (!main_parsing(av, ac, &stack_a))
			return (ft_stack_clear(&stack_a), 0);
		if (is_sorted(stack_a))
			return (ft_stack_clear(&stack_a), 0);
		sort_stack(&stack_a, &stack_b);
		// if (is_sorted(stack_a))
		// 	ft_printf("yes");
		// else
		// 	ft_printf("no");
	}
	ft_free_stacks(stack_a, stack_b);
	return (0);
}
