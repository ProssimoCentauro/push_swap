#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/header_files/ft_printf.h"
# include "../libft/header_files/get_next_line.h"
# include "../libft/header_files/libft.h"
# include <stdio.h>
# include <stdlib.h>

# define MALLOC_ERROR "\n\033[1;31m><>< MALLOC ERROR ><><\033[0m\n\n"
# define INPUT_ERROR "Error\n"

//////////////////////////////////////////////////////////
///

typedef struct  s_indexes
{
    int a_index;
    int b_index;
}   t_indexes;

typedef struct  s_best
{
	int	rb;
	int	rrb;
    int a_index;
    int b_index;
    int a_moves;
    int b_moves;
    int moves;
}   t_best;

	// moves
void		sa(t_list **a, int flag);
void		sb(t_list **b, int flag);
void		ss(t_list **a, t_list **b);
void		pa(t_list **a, t_list **b, int flag);
void		pb(t_list **a, t_list **b, int flag);
void		ra(t_list **a, int flag);
void		rb(t_list **b, int flag);
void		rr(t_list **a, t_list **b);
void		rra(t_list **a, int flag);
void		rrb(t_list **b, int flag);
void		rrr(t_list **a, t_list **b);

void    print_stack(t_list *lst, char c);
void	three_sort(t_list **lst);
void    free_matrix(char ***matrix);
void    content_del(void *content);
void    free_and_exit(t_list **lst, void (*del)(void *), char *message);
int     check_args(char **args);
int     check_duplicates(t_list *lst);
long    ft_atol(char *nptr);
void    create_list(t_list **lst, char ***matrix);
t_list  *find_max(t_list *lst);
void    parse_args(t_list **a_stack, char **av);
int     sorted(t_list *stack);

//algo.c
int     detect_half(t_list *lst, long *num);
int     ft_max(int a, int b);
int     same_sign(int a, int b);
int     ft_abs(int num);
long    get_num(int index, t_list *lst);
void    update_best(t_best *best, t_indexes *indxs, t_list *a, t_list *b);
int     max_min(long num, t_list *b_stack);
int     get_index(t_list *lst, long *num);
long    calc_b_num(long *a_num, t_list *b);
void    move_same_sign(t_best *best, t_list **a, t_list **b);
void    move_case_1(t_best *best, t_list **a, t_list **b);
void    move_case_2(t_best *best, t_list **a, t_list **b);
void    move_case_3(t_best *best, t_list **a, t_list **b);
void    rotate_and_push(t_best *best, t_list **a, t_list **b);
void    best_init(t_best *best);
long    get_max(t_list *stack);
void    rot_to_min(t_list **stack, int flag);
void    rot_to_max(t_list **stack, int flag);
void    rotate_a(t_list **a, int index);
long    calc_a_num(long *b_num, t_list *a);
long    get_min(t_list *stack);
void    few_push_all(t_list **a, t_list **b);
void    few_cheapest_num(t_list **a, t_list **b);
void    push_all(t_list **a, t_list **b);
void    cheapest_num(t_list **a, t_list **b);
void    select_algo(t_list **a, t_list **b);
void    two_sort(t_list **a);

#endif
