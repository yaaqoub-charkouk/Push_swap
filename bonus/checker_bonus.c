/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 13:49:09 by ycharkou          #+#    #+#             */
/*   Updated: 2025/02/25 09:47:46 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*move;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (ft_error(2), 1);
	else
	{
		if (!main_parsing(av, ac, &stack_a))
			return (ft_stack_clear(&stack_a), 0);
		move = get_next_line(0);
		while (move)
		{
			apply_move(&stack_a, &stack_b, move);
			move = get_next_line(0);
		}
		free(move);
		if (is_sorted(stack_a) && !stack_b)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	return (ft_free_stacks(stack_a, stack_b), 0);
}
