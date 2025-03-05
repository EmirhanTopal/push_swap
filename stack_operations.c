/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stach_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:16:18 by marvin            #+#    #+#             */
/*   Updated: 2025/03/04 16:16:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_node	*ft_init_stack(int argc, char **argv)
{
	t_node  *a;
    char    **args;

    a = NULL;
    args = ft_fill_stack(&a, argc, argv);
    // argc == 2 Durumu:
    //Eğer argc == 2 ise, args dizisi dinamik olarak ayrılmıştır çünkü argv[1]'den gelen string ayrıştırılmıştır.
    //Bu durumda, args dizisi artık kullanılmayacaksa, 
    //bellekte gereksiz yer kaplamaması için free edilmelidir.
    if (argc == 2)
        free(args);
    return (a);
}

char    **ft_fill_stack(t_node **stack, int argc, char **argv)
{
    char	    **args;
    long long	num;
	int		    i;

	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv + 1;
	i = 0;
    while (args[i])
    {
        if (!ft_is_number(args[i])) // Sayı mı kontrolü
        {
            write(2, "Hata: Geçersiz karakter\n", 24);
            ft_free_stack(stack);
            return (NULL);
        }
        if (!ft_atoi_check(args[i], &num)) // Integer sınır kontrolü
        {
            write(2, "Hata: Sayı sınırı aşıldı\n", 26);
            ft_free_stack(stack);
            return (NULL);
        }
        ft_add_node_front(stack, num);
        if (ft_duplicate_control(*stack)) // Tekrar eden sayı kontrolü
        {
            printf("Tekrar eden sayı bulundu, ekleme yapılmıyor!\n");
            write(2, "Hata: Tekrar eden sayı var\n", 28);
            ft_free_stack(stack);
            return (NULL);
        }
        i++;
    }
    return (args);
}

int	ft_stack_length(t_node *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

void	ft_free_stack(t_node **stack)
{
	t_node	*tmp;

	while (*stack)
	{
		tmp = *stack;     // Geçici pointer ile mevcut düğümü tut
		*stack = (*stack)->next;  // Stack’in başını bir sonraki elemana kaydır
		free(tmp);        // Önceki düğümü serbest bırak
	}
	*stack = NULL;
}

void ft_add_node_end(t_node **stack, int num)
{
    t_node *new;
    t_node *last;

    new = (t_node *)malloc(sizeof(t_node));
    if (!new)
        return ;
    new->data = num;
    new->next = NULL;
    if (!*stack) // Stack boşsa yeni düğümü ilk eleman yap
    {
        *stack = new;
        return ;
    }
    last = *stack;
    while (last->next) // Listenin sonuna git
        last = last->next;
    last->next = new; // Yeni düğümü sona bağla
}

void ft_add_node_front(t_node **stack, int num)
{
    t_node *new;

    new = (t_node *)malloc(sizeof(t_node));
    if (!new)
        return ;
    new->data = num;
    new->next = *stack; // Yeni düğümün "next"ini mevcut stack'in başına bağla
    *stack = new; // Stack'in yeni başı artık bu yeni düğüm
}
