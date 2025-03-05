/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:41:37 by marvin            #+#    #+#             */
/*   Updated: 2025/03/04 16:41:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_is_number(char *str)
{
    int i = 0;

    if (str[i] == '-' || str[i] == '+') // Başında - veya + olabilir
        i++;

    if (str[i] == '\0') // Sadece - veya + varsa yanlış
        return (0);

    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

int ft_atoi_check(char *str, long long *num)
{
    long long result;
    int sign;
    int i;

    result = 0;
    sign = 1;
    i = 0;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i])
    {
        result = result * 10 + (str[i] - '0');

        if ((sign * result) > 2147483647 || (sign * result) < -2147483648)
            return (0);
        i++;
    }
    *num = (int)(sign * result);
    return (1);
}

int	ft_is_duplicate(t_node *a, int value)
{
	t_node *current = a;
	while (current)
	{
		if (current->data == value)
			return (1);  // Duplicate bulundu, 1 döndürüyoruz
		current = current->next;
	}
	return (0);  // Duplicate bulunamadı, 0 döndürüyoruz
}

int ft_duplicate_control(t_node *a)
{
	t_node	*current;

	current = a;
	while (current)
	{
		// Eğer bu değeri daha önce gördüysek duplicate var
		if (ft_is_duplicate(current->next, current->data))
            return (1);
		current = current->next;
	}
    return (0);
}

int	ft_sorted_control(t_node *a)
{
	while (a && a->next)
	{
		if (a->data > a->next->data)
			return (0);
		a = a->next;
	}
	return (1);
}