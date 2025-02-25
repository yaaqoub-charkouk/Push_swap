/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:16:13 by ycharkou          #+#    #+#             */
/*   Updated: 2025/02/25 09:57:47 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}	t_stack;

long	ft_atoi(const char *str);
int		ft_isdigit(int c);
char	**ft_split(char const *s, char c);
void	*ft_free_matrix(char **strs);
void	ft_error(int fd);
size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
t_stack	*ft_lstnew(int content);
t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_lst_before_last(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_stack_clear(t_stack **lst);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
int		ft_stack_size(t_stack *lst);

#endif
