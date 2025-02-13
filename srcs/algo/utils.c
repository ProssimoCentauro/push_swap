#include "push_swap.h"

void    two_sort(t_list **a)
{
    if (*((long*)((*a)->content)) > *((long*)(*a)->next->content))
        sa(a, 1);
}


t_list  *find_max(t_list *lst)
{
        long    *num;
        long    *num2;
        t_list  *res;

        if (!lst)
                return (NULL);
        res = lst;
        lst = lst->next;
        while (lst)
        {
                num = (long *)res->content;
                num2 = (long *)lst->content;
                if (*num2 > *num)
                        res = lst;
                lst = lst->next;
        }
        return (res);
}

void    three_sort(t_list **lst)
{
        long    *num;
        long    *num2;
        t_list  *max;

        max = find_max(*lst);
        if (max == *lst)
                ra(lst, 1);
        else if (max == (*lst)->next)
                rra(lst, 1);
        num = (*lst)->content;
        num2 = (*lst)->next->content;
        if (*num > *num2)
                sa(lst, 1);
}

int     sorted(t_list *stack)
{
        long    num;

        if (ft_lstsize(stack) == 0)
                return (0);
        num = *((long *)(stack->content));
        stack = stack->next;
        while (stack)
        {
                if (num > *((long *)(stack->content)))
                        return (0);
                num = *((long *)(stack->content));
                stack = stack->next;
        }
        return (1);
}

