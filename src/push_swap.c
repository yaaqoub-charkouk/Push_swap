/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 08:52:31 by ycharkou          #+#    #+#             */
/*   Updated: 2025/03/06 14:56:57 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac >= 2)
	{
		if (!main_parsing(av, ac, &stack_a))
			return (ft_stack_clear(&stack_a), 1);
		if (is_sorted(stack_a))
			return (ft_stack_clear(&stack_a), 0);
		sort_stack(&stack_a, &stack_b);
	}
	ft_free_stacks(stack_a, stack_b);
	return (0);
}
