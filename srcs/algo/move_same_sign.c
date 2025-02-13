#include "push_swap.h"

void    move_same_sign(t_best *best, t_list **a, t_list **b)
{
        if (best->a_moves >= 0)
        {
                while (best->a_moves > 0 && best->b_moves > 0) // prima era ||
                {
                        // ft_printf("%i\n", best->a_moves);
                        rr(a, b);
                        best->a_moves -= 1;
                        best->b_moves -= 1;
                }
                while (best->a_moves > 0)
                {
                        best->a_moves -= 1;
                        ra(a, 1);
                }
                while (best->b_moves > 0)
                {
                        best->b_moves -= 1;
                        rb(b, 1);
                }
        }
        else if (best->a_moves < 0)
        {
                while (best->a_moves < 0 && best->b_moves < 0)
                {
                        rrr(a, b); // prima era rr
                        best->a_moves += 1;
                        best->b_moves += 1;
                }
                while (best->a_moves < 0)
                {
                        best->a_moves += 1;
                        rra(a, 1);
                }
                while (best->b_moves < 0)
                {
                        best->b_moves += 1;
                        rrb(b, 1);
                }
        }
}

