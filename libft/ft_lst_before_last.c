/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_before_last.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:59:41 by ycharkou          #+#    #+#             */
/*   Updated: 2025/02/25 09:53:38 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_lst_before_last(t_stack *lst)
{
	t_stack	*before_last;

	before_last = lst;
	if (!before_last || !before_last->next)
		return (NULL);
	while (before_last->next->next)
		before_last = before_last->next;
	return (before_last);
}
