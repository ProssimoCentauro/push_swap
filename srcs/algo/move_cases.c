/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cases.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:18:07 by rtodaro           #+#    #+#             */
/*   Updated: 2025/02/14 16:33:44 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_case_1(t_best *best, t_list **a, t_list **b)
{
	while (best->rb > 0)
	{
		rr(a, b);
		best->rb -= 1;
		best->moves -= 1;
	}
	while (best->moves > 0)
	{
		ra(a, 1);
		best->moves -= 1;
	}
}

void	move_case_2(t_best *best, t_list **a, t_list **b)
{
	while (best->rrb < 0)
	{
		rrr(a, b);
		best->rrb += 1;
		best->moves -= 1;
	}
	while (best->moves > 0)
	{
		rra(a, 1);
		best->moves -= 1;
	}
}

static void	move_case_3_a(t_best *best, t_list **a)
{
	if (best->a_moves < 0)
	{
		while (best->a_moves)
		{
			rra(a, 1);
			best->a_moves += 1;
		}
	}
	else if (best->a_moves > 0)
	{
		while (best->a_moves)
		{
			ra(a, 1);
			best->a_moves -= 1;
		}
	}
}

static void	move_case_3_b(t_best *best, t_list **b)
{
	if (best->b_moves < 0)
	{
		while (best->b_moves)
		{
			rrb(b, 1);
			best->b_moves += 1;
		}
	}
	else if (best->b_moves > 0)
	{
		while (best->b_moves)
		{
			rb(b, 1);
			best->b_moves -= 1;
		}
	}
}

void	move_case_3(t_best *best, t_list **a, t_list **b)
{
	move_case_3_a(best, a);
	move_case_3_b(best, b);
}
