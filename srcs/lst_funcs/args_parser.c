/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:57:05 by rtodaro           #+#    #+#             */
/*   Updated: 2025/02/14 15:57:06 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(char **args)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		if (args[i][j] == '+' || args[i][j] == '-')
			j++;
		if (args[i][j] == '\0')
			return (0);
		while (args[i][j] >= '0' && args[i][j] <= '9' && args[i][j] != '\"')
			j++;
		if (args[i][j] != '\0')
			return (0);
		i++;
	}
	if (!args[0])
		return (0);
	return (1);
}

int	check_duplicates(t_list *lst)
{
	long	*num;
	t_list	*to_check;
	t_list	*current;

	if (!lst->next)
		return (1);
	to_check = lst;
	while (to_check)
	{
		current = lst;
		num = to_check->content;
		while (current)
		{
			if (to_check != current)
			{
				if (*num == *((long *)(current->content)))
					return (0);
			}
			current = current->next;
		}
		to_check = to_check->next;
	}
	return (1);
}

long	ft_atol(char *nptr)
{
	int		sign;
	long	num;

	sign = 1;
	num = 0;
	while ((*nptr == ' ') || ((*nptr >= 9) && (*nptr <= 13)))
		nptr++;
	if ((*nptr == '+') || (*nptr == '-'))
	{
		if (*nptr == '-')
			sign = -sign;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		num = (num * 10) + (*nptr - '0');
		nptr++;
	}
	return (num * sign);
}

void	parse_args(t_list **a_stack, char **av)
{
	size_t	i;
	char	**matrix;

	i = 1;
	while (av[i])
	{
		matrix = ft_split(av[i++], ' ');
		if (!matrix)
			free_and_exit(a_stack, content_del, MALLOC_ERROR);
		if (!check_args(matrix))
		{
			free_matrix(&matrix);
			free_and_exit(a_stack, content_del, INPUT_ERROR);
		}
		create_list(a_stack, &matrix);
		free_matrix(&matrix);
	}
	if (check_duplicates(*a_stack) == 0)
		free_and_exit(a_stack, content_del, INPUT_ERROR);
}

void	create_list(t_list **lst, char ***matrix)
{
	t_list	*node;
	long	*num;
	char	**mat;
	size_t	i;

	mat = *matrix;
	i = 0;
	while (mat[i])
	{
		num = (long *)malloc(sizeof(long));
		if (!num)
			free_and_exit(lst, content_del, MALLOC_ERROR);
		*num = ft_atol(mat[i]);
		if (*num > 2147483647 || *num < -2147483648)
		{
			free_matrix(matrix);
			free(num);
			free_and_exit(lst, content_del, INPUT_ERROR);
		}
		node = ft_lstnew(num);
		if (!node)
			free_and_exit(lst, content_del, MALLOC_ERROR);
		ft_lstadd_back(lst, node);
		i++;
	}
}
