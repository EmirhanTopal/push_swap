/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:49:10 by marvin            #+#    #+#             */
/*   Updated: 2025/03/03 12:49:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void ft_push(t_node **src, t_node **dst)
{
	t_node *tmp;

	if (!src || !*src)
	{
		return;
	}
	tmp = *src; // 5
	*src = (*src)->next; // 3
	tmp->next = *dst; // 5 7 4
	*dst = tmp;
}

void	ft_pa(t_node **a, t_node **b)
{
	ft_push(b, a);
}

void	ft_pb(t_node **a, t_node **b)
{
	ft_push(a, b);
}
