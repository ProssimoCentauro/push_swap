#include "push_swap.h"

void    best_init(t_best *best)
{
        best->rb = 0;
        best->rrb = 0;
        best->a_index = 0;
        best->b_index = 0;
        best->a_moves = 0;
        best->b_moves = 0;
        best->moves = 2147483647;
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
