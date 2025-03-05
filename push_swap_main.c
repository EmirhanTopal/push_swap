#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    t_node *a;
    t_node *b;

    b = NULL;
    if (argc < 2)
    {
        printf("Kullanım: ./push_swap [sayılar]\n");
        return (0);
    }
    a = ft_init_stack(argc, argv); // Stack'i doldur

    // Stack'in oluşup oluşmadığını yazdır
    b = a;
    printf("Stack içeriği:\n");
    while (b)
    {
        printf("%d -> ", b->data);
        b = b->next;
    }
    printf("NULL\n");
    ft_free_stack(&a);
    ft_free_stack(&b);
    return (0);
}
