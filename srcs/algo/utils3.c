/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:05:35 by rtodaro           #+#    #+#             */
/*   Updated: 2025/02/14 17:05:41 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	best_init(t_best *best)
{
	best->rb = 0;
	best->rrb = 0;
	best->a_index = 0;
	best->b_index = 0;
	best->a_moves = 0;
	best->b_moves = 0;
	best->moves = 2147483647;
}
