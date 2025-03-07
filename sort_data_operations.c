/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_data_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:14:47 by marvin            #+#    #+#             */
/*   Updated: 2025/03/05 14:14:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_max_bits(t_node *stack)
{
    int max = -2147483648;
    int bits = 0;

    while (stack)
    {
        if (stack->data > max)
            max = stack->data;
        stack = stack->next;
    }
    while ((max >> bits) != 0)
        bits++;
    return bits;
}

void	ft_index_stack(t_node *a)
{
	t_node	*ptr1;
	t_node	*ptr2;
	int		index;

	ptr1 = a;
	while (ptr1)
	{
		index = 0;
		ptr2 = a;
		while (ptr2)
		{
			if (ptr1->data > ptr2->data)
				index++;
			ptr2 = ptr2->next;
		}
		ptr1->index = index;
		ptr1 = ptr1->next;
	}
}

int	ft_find_max_bit(t_node **a)
{
	t_node	*current;
	int		max_index;
	int		max_bit;

	current = *a;
	if (!current)  // Boş liste kontrolü ekleyin
        return (0);  // veya uygun bir hata değeri döndürebilirsiniz
	max_index = current->index;
	max_bit = 0;
	while (current != NULL)
	{
		if (current->index > max_index)
			max_index = current->index;
		current = current->next;
	}
	if (max_index == 0)
		return (0);
	while (max_index > 0)
	{
		max_index = max_index >> 1;
		max_bit++;
	}
	return (max_bit);
}




