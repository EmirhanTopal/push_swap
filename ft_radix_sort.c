/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:58:12 by marvin            #+#    #+#             */
/*   Updated: 2025/03/06 13:58:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_radix_sort(t_node **a, t_node **b)
{
	int size;
    int max_bit;
    int i;
    int j;

    size = ft_stack_length(*a);
    max_bit = ft_find_max_bit(a);
    i = 0;
    while (i < max_bit)
    {
        j = 0;
        while (j < size)
        {
            if ((((*a)->index >> i) & 1) == 0)
                ft_pb(a, b);
            else
                ft_ra(a);
            j++;
        }
        while (*b)
            ft_pa(a, b);
        i++;    
    }
}
