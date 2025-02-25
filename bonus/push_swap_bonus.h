/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 12:32:30 by ycharkou          #+#    #+#             */
/*   Updated: 2025/02/25 09:50:13 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"

int		main_parsing(char **av, int ac, t_stack **a);
int		push(t_stack **from, t_stack **to);
int		swap(t_stack **stack);
int		rotate(t_stack **stack);
int		reverse_rotate(t_stack **stack);
int		is_sorted(t_stack *stack);
void	ft_free_stacks(t_stack *a, t_stack *b);
void	apply_move(t_stack **a, t_stack **b, char *move);

#endif