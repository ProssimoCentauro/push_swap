#include "push_swap.h"

void    update_best(t_best *best, t_indexes *indxs, t_list *a, t_list *b)
{
        int             ra;
        int             rb;
        int             rra;
        int             rrb;
        t_best  tmp_best;

        ra = indxs->a_index;
        rb = indxs->b_index;
        rra = indxs->a_index - ft_lstsize(a);
        rrb = indxs->b_index - ft_lstsize(b);
        if (ra < (rra * -1))
                tmp_best.a_moves = ra;
        else
                tmp_best.a_moves = rra;
        if (rb < (rrb * -1))
                tmp_best.b_moves = rb;
        else
                tmp_best.b_moves = rrb;
        // calcolo numero totale di mosse
        if (same_sign(tmp_best.a_moves, tmp_best.b_moves))
                tmp_best.moves = ft_max(ft_abs(tmp_best.a_moves),
                                ft_abs(tmp_best.b_moves));
        else
        {
                // in teoria
                // rb = a b_index
                if (tmp_best.a_moves >= 0 && tmp_best.a_moves >= rb)
                        tmp_best.moves = tmp_best.a_moves;
                // rrb uguale a b_moves
                else if (tmp_best.a_moves < 0 && tmp_best.a_moves <= rrb)
                        tmp_best.moves = ft_abs(tmp_best.a_moves);
                else
                {
                        tmp_best.moves = ft_abs(tmp_best.a_moves)
                                + ft_abs(tmp_best.b_moves);
                }
        }
        // controllare se è il best
        if (tmp_best.moves < best->moves)
        {
                best->rb = rb;
                best->rrb = rrb;
                best->a_index = indxs->a_index;
                best->b_index = indxs->b_index;
                best->a_moves = tmp_best.a_moves;
                best->b_moves = tmp_best.b_moves;
                best->moves = tmp_best.moves;
        }
}
