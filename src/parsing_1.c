#include "../push_swap.h"




int	is_valid_number(char *str)
{
	int i = 0;

	if (!str[i])
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (ft_error(2), 0);
		i++;
	}
	return (1);
}

int	main_parsing(char **av, int ac, t_stack **a)
{
	char	 **numbers;
	int 	i;
	int 	j;
	long	num;

	i = 0;
	while (++i < ac)
	{
		j = 0;
		numbers = ft_split(av[i], ' ');
		if (!numbers || !numbers[0])
			return (ft_free_matrix(numbers), ft_error(2), 0);
		while (numbers[j])
		{
			if (!is_valid_number(numbers[j]))
				return (ft_free_matrix(numbers), 0);
			num = ft_atoi(numbers[j]);
			if (num < INT_MIN || num > INT_MAX)
				return (ft_error(2), 0);
			store_in_stack(a, num);
			j++;
		}
		ft_free_matrix(numbers);
	}
	return (1);
}
