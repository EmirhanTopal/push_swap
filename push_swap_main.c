#include "push_swap.h"
#include <stdio.h>

void print_stack(t_node *stack)
{
    while (stack)
    {
        printf("%d \n", stack->data);
        stack = stack->next;
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    t_node *a;
    t_node *b;

    b = NULL;
    if (argc < 2)
    {
        //printf("Kullanım: ./push_swap [sayılar]\n");
        return (0);
    }
    a = ft_init_stack(argc, argv); // Stack'i doldur
    //print_stack(a);
    if (!a)
    {
        ft_free_stack(&a);
        ft_free_stack(&b);
    }
    ft_index_stack(a);
    ft_radix_sort(&a, &b);
    if (!ft_sorted_control(a))
    {
        printf("kral it is not sorted");
        ft_free_stack(&a);
        ft_free_stack(&b);
    }
    return (0);
}
