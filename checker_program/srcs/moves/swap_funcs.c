#include "checker.h"

void    sa(t_list **a, int flag)
{
        t_list  *temp;

        if (!*a || !(*a)->next)
                return ;
        temp = (*a)->next;
        (*a)->next = temp->next;
        temp->next = *a;
        *a = temp;
        if (flag == 1)
                ft_printf("sa\n");
}

void    sb(t_list **b, int flag)
{
        t_list  *temp;

        if (!*b || !(*b)->next)
                return ;
        temp = (*b)->next;
        (*b)->next = temp->next;
        temp->next = *b;
        *b = temp;
        if (flag == 1)
                ft_printf("sb\n");
}

void    ss(t_list **a, t_list **b, int flag)
{
        sa(a, 0);
        sb(b, 0);
        if (flag == 1)
            ft_printf("ss\n");
}

