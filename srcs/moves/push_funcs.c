/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:56:33 by rtodaro           #+#    #+#             */
/*   Updated: 2025/02/14 15:56:35 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **a, t_list **b, int flag)
{
	t_list	*temp;

	if (!b || !*b)
		return ;
	temp = (*b)->next;
	(*b)->next = *a;
	*a = *b;
	*b = temp;
	if (flag == 1)
		ft_printf("pa\n");
}

void	pb(t_list **a, t_list **b, int flag)
{
	t_list	*temp;

	if (!a || !*a)
		return ;
	temp = (*a)->next;
	(*a)->next = *b;
	*b = *a;
	*a = temp;
	if (flag == 1)
		ft_printf("pb\n");
}
