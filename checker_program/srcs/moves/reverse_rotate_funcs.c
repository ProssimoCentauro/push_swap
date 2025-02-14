#include "checker.h"

void    rra(t_list **a, int flag)
{
        t_list  *temp;
        t_list  *last;

        if (!a || !*a || !(*a)->next)
                return ;
        temp = *a;
        while (temp->next->next)
                temp = temp->next;
        last = temp->next;
        temp->next = NULL;
        last->next = *a;
        *a = last;
        if (flag == 1)
                ft_printf("rra\n");
}

void    rrb(t_list **b, int flag)
{
        t_list  *temp;
        t_list  *last;

        if (!b || !*b || !(*b)->next)
                return ;
        temp = *b;
        while (temp->next->next)
                temp = temp->next;
        last = temp->next;
        temp->next = NULL;
        last->next = *b;
        *b = last;
        if (flag == 1)
                ft_printf("rrb\n");
}

void    rrr(t_list **a, t_list **b, int flag)
{
        rra(a, 0);
        rra(b, 0);
        if (flag == 1)
            ft_printf("rrr\n");
}

