/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:47:42 by ycharkou          #+#    #+#             */
/*   Updated: 2025/02/19 12:05:24 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_and_exit(t_stack **a, char **numbers)
{
	ft_error(2);
	ft_free_matrix(numbers);
	ft_stack_clear(a);
	exit(EXIT_FAILURE);
}

int	has_duplicate(t_stack *a, int num)
{
	while (a)
	{
		if (num == a->content)
			return (1);
		a = a->next;
	}
	return (0);
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	helper(t_stack **a, char **numbers, int j)
{
	long	num;

	if (!is_valid_number(numbers[j]))
		free_and_exit(a, numbers);
	num = ft_atoi(numbers[j]);
	if (num < INT_MIN || num > INT_MAX)
		free_and_exit(a, numbers);
	if (has_duplicate(*a, num) == 1)
		free_and_exit(a, numbers);
	store_in_stack(a, num);
}

int	main_parsing(char **av, int ac, t_stack **a)
{
	char	**numbers;
	int		i;
	int		j;

	i = 0;
	while (++i < ac)
	{
		j = 0;
		numbers = ft_split(av[i], ' ');
		if (!numbers || !numbers[0])
			return (ft_free_matrix(numbers), ft_error(2), 0);
		while (numbers[j])
		{
			helper(a, numbers, j);
			j++;
		}
		ft_free_matrix(numbers);
	}
	return (1);
}
