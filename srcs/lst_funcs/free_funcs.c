/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:57:11 by rtodaro           #+#    #+#             */
/*   Updated: 2025/02/15 12:01:27 by rtodaro          ###   ########.fr       */
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

void	free_and_exit(t_list **lst, void (*del)(void *), int error)
{
	if (lst)
		ft_lstclear(lst, del);
	if (error == 0)
		write(2, INPUT_ERROR, 6);
	if (error == 1)
		write(2, MALLOC_ERROR, 16);
	exit(EXIT_FAILURE);
}
