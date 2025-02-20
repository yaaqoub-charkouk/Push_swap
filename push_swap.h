/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:25:59 by ycharkou          #+#    #+#             */
/*   Updated: 2025/02/20 17:39:57 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

int		main_parsing(char **av, int ac, t_stack **a);
void	store_in_stack(t_stack **stack, int value);
void	free_and_exit(t_stack **a, char **numbers);
int     is_sorted(t_stack *stack);
int     get_max(t_stack *stack);
int	    get_min(t_stack *stack);
void	sort_stack(t_stack *a, t_stack *b);

// moves
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);


void print_stack(t_stack *a);
#endif