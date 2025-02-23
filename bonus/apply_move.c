/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 13:51:50 by ycharkou          #+#    #+#             */
/*   Updated: 2025/02/23 13:51:51 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
}