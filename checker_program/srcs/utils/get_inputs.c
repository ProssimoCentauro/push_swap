/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_inputs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:54:05 by rtodaro           #+#    #+#             */
/*   Updated: 2025/02/14 15:54:07 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	select_move(char *str, t_list **a, t_list **b)
{
	if (!ft_strcmp(str, "pa\n"))
		pa(a, b, 0);
	else if (!ft_strcmp(str, "pb\n"))
		pb(a, b, 0);
	else if (!ft_strcmp(str, "sa\n"))
		sa(a, 0);
	else if (!ft_strcmp(str, "sb\n"))
		sb(b, 0);
	else if (!ft_strcmp(str, "ss\n"))
		ss(a, b, 0);
	else if (!ft_strcmp(str, "ra\n"))
		ra(a, 0);
	else if (!ft_strcmp(str, "rb\n"))
		rb(b, 0);
	else if (!ft_strcmp(str, "rr\n"))
		rr(a, b, 0);
	else if (!ft_strcmp(str, "rra\n"))
		rra(a, 0);
	else if (!ft_strcmp(str, "rrb\n"))
		rrb(b, 0);
	else if (!ft_strcmp(str, "rrr\n"))
		rrr(a, b, 0);
	else
		return (0);
	return (1);
}

void	exit_on_error(char **str, t_list **a, t_list **b)
{
	free(*str);
	ft_lstclear(a, content_del);
	ft_lstclear(b, content_del);
	ft_printf("%s", INPUT_ERROR);
	exit(EXIT_FAILURE);
}

void	get_inputs(t_list **a, t_list **b)
{
	char	*str;

	while (42)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		if (!select_move(str, a, b))
			exit_on_error(&str, a, b);
		free(str);
	}
}
