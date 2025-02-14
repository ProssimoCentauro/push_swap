/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:54:11 by rtodaro           #+#    #+#             */
/*   Updated: 2025/02/14 15:54:13 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	sorted(t_list *stack)
{
	long	num;

	if (ft_lstsize(stack) == 0)
		return (0);
	num = *((long *)(stack->content));
	stack = stack->next;
	while (stack)
	{
		if (num > *((long *)(stack->content)))
			return (0);
		num = *((long *)(stack->content));
		stack = stack->next;
	}
	return (1);
}
