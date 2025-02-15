/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_best.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:04:39 by rtodaro           #+#    #+#             */
/*   Updated: 2025/02/15 12:31:35 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_moves(t_best *tmp_best, int rb, int rrb)
{
	if (same_sign(tmp_best->a_moves, tmp_best->b_moves))
		tmp_best->moves = ft_max(ft_abs(tmp_best->a_moves),
				ft_abs(tmp_best->b_moves));
	else
	{
		if (tmp_best->a_moves >= 0 && tmp_best->a_moves >= rb)
			tmp_best->moves = tmp_best->a_moves;
		else if (tmp_best->a_moves < 0 && tmp_best->a_moves <= rrb)
			tmp_best->moves = ft_abs(tmp_best->a_moves);
		else
		{
			tmp_best->moves = ft_abs(tmp_best->a_moves)
				+ ft_abs(tmp_best->b_moves);
		}
	}
}

static void	new_best(t_best *best, t_best *tmp_best, t_indexes *indxs)
{
	best->a_index = indxs->a_index;
	best->b_index = indxs->b_index;
	best->a_moves = tmp_best->a_moves;
	best->b_moves = tmp_best->b_moves;
	best->moves = tmp_best->moves;
}

static void	rot_update(t_best *tmp_best, int r, int rr, int flag)
{
	if (flag == 0)
	{
		if (r < (rr * -1))
			tmp_best->a_moves = r;
		else
			tmp_best->a_moves = rr;
	}
	else
	{
		if (r < (rr * -1))
			tmp_best->b_moves = r;
		else
			tmp_best->b_moves = rr;
	}
}

void	update_best(t_best *best, t_indexes *indxs, t_list *a, t_list *b)
{
	int		ra;
	int		rb;
	int		rra;
	int		rrb;
	t_best	tmp_best;

	ra = indxs->a_index;
	rb = indxs->b_index;
	rra = indxs->a_index - ft_lstsize(a);
	rrb = indxs->b_index - ft_lstsize(b);
	rot_update(&tmp_best, ra, rra, 0);
	rot_update(&tmp_best, rb, rrb, 1);
	set_moves(&tmp_best, rb, rrb);
	if (tmp_best.moves < best->moves)
	{
		best->rb = rb;
		best->rrb = rrb;
		new_best(best, &tmp_best, indxs);
	}
}
