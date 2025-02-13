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
