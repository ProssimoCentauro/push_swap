/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:54:54 by rtodaro           #+#    #+#             */
/*   Updated: 2025/02/14 15:54:55 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	ft_printf("%s", message);
	exit(EXIT_FAILURE);
}
