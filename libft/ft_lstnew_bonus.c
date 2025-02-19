/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycharkou <ycharkou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:14:50 by ycharkou          #+#    #+#             */
/*   Updated: 2025/02/19 12:10:23 by ycharkou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_lstnew(int content)
{
	t_stack	*node1;

	node1 = malloc(sizeof(t_stack));
	if (!node1)
		return (NULL);
	node1->content = content;
	node1->next = NULL;
	return (node1);
}
