/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:56:41 by rtodaro           #+#    #+#             */
/*   Updated: 2025/02/14 15:56:42 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **a, int flag)
{
	t_list	*temp;

	if (!a || !*a || !(*a)->next)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = NULL;
	ft_lstadd_back(a, temp);
	if (flag == 1)
		ft_printf("ra\n");
}

void	rb(t_list **b, int flag)
{
	t_list	*temp;

	if (!b || !*b || !(*b)->next)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = NULL;
	ft_lstadd_back(b, temp);
	if (flag == 1)
		ft_printf("rb\n");
}

void	rr(t_list **a, t_list **b)
{
	ra(a, 0);
	rb(b, 0);
	ft_printf("rr\n");
}
