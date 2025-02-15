/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 17:04:22 by rtodaro           #+#    #+#             */
/*   Updated: 2025/02/15 17:04:22 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_len(char *str)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\"')
	{
		i++;
		count++;
		if (count >= 11)
			return (0);
	}
	if (str[i] != '\0')
		return (0);
	return (1);
}
