/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_same_sign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:22:55 by rtodaro           #+#    #+#             */
/*   Updated: 2025/02/14 16:22:56 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	greater_than_zero(t_best *best, t_list **a, t_list **b)
{
	while (best->a_moves > 0 && best->b_moves > 0)
	{
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

static void	less_than_zero(t_best *best, t_list **a, t_list **b)
{
	while (best->a_moves < 0 && best->b_moves < 0)
	{
		rrr(a, b);
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

void	move_same_sign(t_best *best, t_list **a, t_list **b)
{
	if (best->a_moves >= 0)
		greater_than_zero(best, a, b);
	else if (best->a_moves < 0)
		less_than_zero(best, a, b);
}
