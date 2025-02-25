/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 13:51:50 by ycharkou          #+#    #+#             */
/*   Updated: 2025/02/25 09:47:07 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_valid_move(char *move)
{
	if (!ft_strcmp(move, "sa") || !ft_strcmp(move, "ss"))
		return (1);
	if (!ft_strcmp(move, "sb"))
		return (1);
	if (!ft_strcmp(move, "pa"))
		return (1);
	if (!ft_strcmp(move, "pb"))
		return (1);
	if (!ft_strcmp(move, "ra") || !ft_strcmp(move, "rr"))
		return (1);
	if (!ft_strcmp(move, "rb"))
		return (1);
	if (!ft_strcmp(move, "rra") || !ft_strcmp(move, "rrr"))
		return (1);
	if (!ft_strcmp(move, "rrb"))
		return (1);
	return (0);
}

void	apply_move(t_stack **a, t_stack **b, char *move)
{
	if (!ft_strcmp(move, "sa") || !ft_strcmp(move, "ss"))
		swap(a);
	if (!ft_strcmp(move, "sb") || !ft_strcmp(move, "ss"))
		swap(b);
	if (!ft_strcmp(move, "pa"))
		push(b, a);
	if (!ft_strcmp(move, "pb"))
		push(a, b);
	if (!ft_strcmp(move, "ra") || !ft_strcmp(move, "rr"))
		rotate(a);
	if (!ft_strcmp(move, "rb") || !ft_strcmp(move, "rr"))
		rotate(b);
	if (!ft_strcmp(move, "rra") || !ft_strcmp(move, "rrr"))
		reverse_rotate(a);
	if (!ft_strcmp(move, "rrb") || !ft_strcmp(move, "rrr"))
		reverse_rotate(b);
	if (!is_valid_move(move))
	{
		ft_error(2);
		ft_free_stacks(*a, *b);
		free(move);
		exit(EXIT_FAILURE);
	}
	free(move);
}
