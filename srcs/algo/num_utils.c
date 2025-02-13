#include "push_swap.h"

int     max_min(long num, t_list *b_stack)
{
        t_list  *head;
        int             flag;

        head = b_stack;
        flag = 1;
        while (b_stack)
        {
                if (*((long *)(b_stack->content)) > num)
                {
                        flag = 0;
                        break ;
                }
                b_stack = b_stack->next;
        }
        if (flag == 1)
                return (1);
        b_stack = head;
        while (b_stack)
        {
                if (*((long *)(b_stack->content)) < num)
                        return (0);
                b_stack = b_stack->next;
        }
        return (1);
}


long    calc_b_num(long *a_num, t_list *b)
{
        long    res;
        t_list  *head;

        res = -2147483648;
        head = b;
        if (!max_min(*a_num, b))
        {
                while (b->next)
                {
                        if (*a_num < *((long *)(b->content))
                                && *a_num > *((long *)(b->next->content)))
                                return (*((long *)(b->next->content)));
                        b = b->next;
                }
                return (*((long *)(head->content)));
        }
        while (b)
        {
                if (res < *((long *)(b->content)))
                        res = *((long *)(b->content));
                b = b->next;
        }
        return (res);
}

long    calc_a_num(long *b_num, t_list *a)
{
        long    res;
        t_list  *head;

        res = 2147483647;
        head = a;
        if (!max_min(*b_num, a))
        {
                while (a->next)
                {
                        if (*b_num > *((long *)(a->content))
                                && *b_num < *((long *)(a->next->content)))
                                return (*((long *)(a->next->content)));
                        a = a->next;
                }
                return (*((long *)(head->content)));
        }
        while (a)
        {
                if (res > *((long *)(a->content)))
                        res = *((long *)(a->content));
                a = a->next;
        }
        if (get_index(a, &res) == ft_lstsize(a) - 1)
            return (0);
        return (res);
}

long    get_min(t_list *stack)
{
        long    min;

        min = 2147483647;
        while (stack)
        {
                if (min > *((long *)(stack->content)))
                        min = *((long *)(stack->content));
                stack = stack->next;
        }
        return (min);
}

long    get_max(t_list *stack)
{
        long    max;

        max = -2147483648;
        while (stack)
        {
                if (max < *((long *)(stack->content)))
                        max = *((long *)(stack->content));
                stack = stack->next;
        }
        return (max);
}

