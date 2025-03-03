/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 14:32:59 by marvin            #+#    #+#             */
/*   Updated: 2025/03/03 14:32:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static 	void		ft_swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !*stack || !(*stack)->next)
	{
		return;
	}	
	first = *stack;
	second = first->next;
	first->next = second->next; // İlk düğüm artık üçüncü düğüme bağlanıyor
	second->next = first; // İkinci düğüm, ilk düğümün önüne geçiyor
	*stack = second; // Yeni baş ikinci düğüm oluyor
}

void	ft_sa(t_node **a)
{
	ft_swap(a);
}

void	ft_sb(t_node **b)
{
	ft_swap(b);
}

void	ft_ss(t_node **a, t_node **b)
{
	ft_swap(a);
	ft_swap(b);
}