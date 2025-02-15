/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:32:13 by rtodaro           #+#    #+#             */
/*   Updated: 2025/02/15 12:38:51 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../../libft/header_files/ft_printf.h"
# include "../../libft/header_files/get_next_line.h"
# include "../../libft/header_files/libft.h"
# include <stdio.h>
# include <stdlib.h>

# define MALLOC_ERROR "> MALLOC ERROR <"
# define INPUT_ERROR "Error\n"

//////////////////////////////////////////////////////////
///

// moves
void	sa(t_list **a, int flag);
void	sb(t_list **b, int flag);
void	ss(t_list **a, t_list **b, int flag);
void	pa(t_list **a, t_list **b, int flag);
void	pb(t_list **a, t_list **b, int flag);
void	ra(t_list **a, int flag);
void	rb(t_list **b, int flag);
void	rr(t_list **a, t_list **b, int flag);
void	rra(t_list **a, int flag);
void	rrb(t_list **b, int flag);
void	rrr(t_list **a, t_list **b, int flag);

void	free_matrix(char ***matrix);
void	content_del(void *content);
void	free_and_exit(t_list **lst, void (*del)(void *), int error);
int		check_args(char **args);
int		check_duplicates(t_list *lst);
long	ft_atol(char *nptr);
void	create_list(t_list **lst, char ***matrix);
void	parse_args(t_list **a_stack, char **av);
int		sorted(t_list *stack);
int		check_len(char *str);

// get inputs
int		select_move(char *str, t_list **a, t_list **b);
void	get_inputs(t_list **a, t_list **b);
int		ft_strcmp(char *s1, char *s2);
void	exit_on_error(char **str, t_list **a, t_list **b);

#endif
