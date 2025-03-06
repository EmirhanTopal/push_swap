/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:50:32 by marvin            #+#    #+#             */
/*   Updated: 2025/03/03 14:50:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// top **  top
// 3		2
// 2		1
// 1		3

// 1 2 3 4
void	ft_rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
	{
		return ;
	}
	first = *stack; // ilk node (1)
	*stack = first->next; // ilk node artık (2)
	first->next = NULL; // 1->next = NULL
	last = *stack; // 2
	while (last->next) // 2 3 4
		last = last->next; 
	//last = 4 , 4->next = NULL
	last->next = first;
	
}

void	ft_ra(t_node **a)
{
	write(1, "ra\n", 3);
	ft_rotate(a);
}

void	ft_rb(t_node **b)
{
	write(1, "ra\n", 3);
	ft_rotate(b);
}

void	ft_rr(t_node **a, t_node **b)
{
	write(1, "rr\n", 3);
	ft_rotate(a);
	ft_rotate(b);
}