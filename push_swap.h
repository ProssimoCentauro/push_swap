#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/header_files/ft_printf.h"
# include "libft/header_files/get_next_line.h"
# include "libft/header_files/libft.h"
# include <stdio.h>
# include <stdlib.h>

# define MALLOC_ERROR "\n\033[1;31m><>< MALLOC ERROR ><><\033[0m\n\n"
# define INPUT_ERROR "Error\n"

typedef struct s_directions
{
	int	a_dir;
	int	b_dir;
} t_directions;

	// moves
void    sa(t_list **a, int flag);
void	sb(t_list **b, int flag);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b, int flag);
void	pb(t_list **a, t_list **b, int flag);
void	ra(t_list **a, int flag);
void	rb(t_list **b, int flag);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a, int flag);
void	rrb(t_list **b, int flag);
void	rrr(t_list **a, t_list **b);
#endif
