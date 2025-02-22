/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:15:37 by ycharkou          #+#    #+#             */
/*   Updated: 2025/02/22 16:10:54 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static size_t	ft_count_words(char const *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

void	*ft_free_matrix(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

static char	*fill_word(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = 0;
	return (word);
}

static char	**ft_split_words(const char *s, char c, char **buffer, size_t len)
{
	size_t	start;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	start = 0;
	while (i <= len)
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			start = i;
		if (s[i] == c || i == len)
		{
			if (i > 0 && s[i - 1] != c)
			{
				buffer[j] = fill_word(s, start, i);
				if (!buffer[j])
					return (ft_free_matrix(buffer));
				j++;
			}
		}
		i++;
	}
	return (buffer);
}

char	**ft_split(char const *s, char c)
{
	char	**buffer;
	size_t	len;
	size_t	words_count;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	words_count = ft_count_words(s, c);
	if (*s == '\0' || words_count == 0)
		return (NULL);
	buffer = ft_calloc((words_count + 1), sizeof(char *));
	if (!buffer)
		return (NULL);
	return (ft_split_words(s, c, buffer, len));
}

// int main(int ac, char **av)
// {
// 	char **s;

// 	s = ft_split(av[1], ' ');
// 	printf("%s\n", s[0]);
// 	return (0);
// }
