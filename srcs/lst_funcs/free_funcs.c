/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:57:11 by rtodaro           #+#    #+#             */
/*   Updated: 2025/02/14 18:34:13 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_matrix(char ***matrix)
{
	char	**mat;
	size_t	i;

	mat = *matrix;
	i = 0;
	while (mat[i])
	{
		free(mat[i]);
		mat[i++] = NULL;
	}
	free(mat);
	mat = NULL;
}

void	content_del(void *content)
{
	free(content);
}

void	free_and_exit(t_list **lst, void (*del)(void *), char *message)
{
	if (lst)
		ft_lstclear(lst, del);
	write(2, message, 6);
	exit(EXIT_FAILURE);
}
