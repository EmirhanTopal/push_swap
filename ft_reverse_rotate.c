/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:10:16 by marvin            #+#    #+#             */
/*   Updated: 2025/03/03 16:10:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_reverse_rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
	{
		return;
	}
	last = *stack;
	//Eğer stack içinde sadece iki eleman varsa, last->next->next erişimi hata verebilir.
	//last->next && last->next->next ifadesi önce last->next kontrolü yaparak hata olasılığını önler.
	while (last->next && last->next->next) // 1 2 3 4 -> 1 (2) 3 4 
	{
		last = last->next;
	}
	first = last->next; // first = 4 last = 3
	first->next = *stack; // 4->next = NULL dı bunu *stack yapıyoruz (1)
	*stack = first; // ilk node 4 
	last->next = NULL; // last->next = (3) NULL / 4 -> 1 -> 2 -> 3 -> NULL
}

void	ft_rra(t_node **a)
{
	write(1, "rra\n", 4);
	ft_reverse_rotate(a);
}

void	ft_rrb(t_node **b)
{
	write(1, "rrb\n", 4);
	ft_reverse_rotate(b);
}

void	ft_rrr(t_node **a, t_node **b)
{
	write(1, "rrr\n", 4);
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
}