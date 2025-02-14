/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_funcs.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:56:38 by rtodaro           #+#    #+#             */
/*   Updated: 2025/02/14 15:56:39 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **a, int flag)
{
	t_list	*temp;
	t_list	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	temp = *a;
	while (temp->next->next)
		temp = temp->next;
	last = temp->next;
	temp->next = NULL;
	last->next = *a;
	*a = last;
	if (flag == 1)
		ft_printf("rra\n");
}

void	rrb(t_list **b, int flag)
{
	t_list	*temp;
	t_list	*last;

	if (!b || !*b || !(*b)->next)
		return ;
	temp = *b;
	while (temp->next->next)
		temp = temp->next;
	last = temp->next;
	temp->next = NULL;
	last->next = *b;
	*b = last;
	if (flag == 1)
		ft_printf("rrb\n");
}

void	rrr(t_list **a, t_list **b)
{
	rra(a, 0);
	rra(b, 0);
	ft_printf("rrr\n");
}
