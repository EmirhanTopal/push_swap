#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    t_node *stack = NULL;
    t_node *tmp;

    if (argc < 2)
    {
        printf("Kullanım: ./push_swap [sayılar]\n");
        return (1);
    }

    ft_fill_stack(&stack, argv + 1); // Stack'i doldur

    // Stack'in oluşup oluşmadığını yazdır
    tmp = stack;
    printf("Stack içeriği:\n");
    while (tmp)
    {
        printf("%d -> ", tmp->data);
        tmp = tmp->next;
    }
    printf("NULL\n");

    return (0);
}
