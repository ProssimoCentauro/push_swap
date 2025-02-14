/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 16:32:19 by rtodaro           #+#    #+#             */
/*   Updated: 2025/02/14 16:32:20 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_list **a, int index)
{
	int	size;
	int	moves;

	size = ft_lstsize(*a);
	if (index <= size)
	{
		moves = index;
		while (moves)
		{
			ra(a, 1);
			moves--;
		}
	}
	else
	{
		moves = ft_abs(index - size);
		while (moves)
		{
			rra(a, 1);
			moves--;
		}
	}
}

static void	check_flag(t_list **stack, int flag, int r_flag)
{
	if (r_flag == 1)
	{
		if (flag == 1)
			ra(stack, 1);
		else
			rb(stack, 1);
	}
	else
	{
		if (flag == 1)
			rra(stack, 1);
		else
			rrb(stack, 1);
	}
}

void	rot_to_max(t_list **stack, int flag)
{
	long	max;
	int		index;
	int		size;

	max = get_max(*stack);
	index = get_index(*stack, &max);
	size = ft_lstsize(*stack);
	if (index <= size / 2)
	{
		while (index > 0)
		{
			check_flag(stack, flag, 1);
			index--;
		}
	}
	else
	{
		index = ft_abs(index - size);
		while (index > 0)
		{
			check_flag(stack, flag, 0);
			index--;
		}
	}
}

void	rot_to_min(t_list **stack, int flag)
{
	long	min;
	int		index;
	int		size;

	min = get_min(*stack);
	index = get_index(*stack, &min);
	size = ft_lstsize(*stack);
	if (index <= size / 2)
	{
		while (index > 0)
		{
			check_flag(stack, flag, 1);
			index--;
		}
	}
	else
	{
		index = ft_abs(index - size);
		while (index > 0)
		{
			check_flag(stack, flag, 0);
			index--;
		}
	}
}

void	rotate_and_push(t_best *best, t_list **a, t_list **b)
{
	if (same_sign(best->a_moves, best->b_moves))
		move_same_sign(best, a, b);
	else if (best->a_moves >= 0 && best->a_moves >= best->rb)
		move_case_1(best, a, b);
	else if (best->a_moves < 0 && best->a_moves <= best->rrb)
		move_case_2(best, a, b);
	else
		move_case_3(best, a, b);
	pb(a, b, 1);
}
