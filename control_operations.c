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

int ft_atoi_check(char *str, int *num)
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

int ft_has_duplicate(t_node *stack, int num)
{
    while (stack)
    {
        if (stack->data == num)
            return (1);
        stack = stack->next;
    }
    return (0);
}

