#include "push_swap.h"

int	max_min(long num, t_list *b_stack)
{
	long	*stack_num;

	while (b_stack)
	{
		stack_num = b_stack->content;
		if (num < *stack_num || *stack_num > num)
			return (0);
		b_stack = b_stack->next;
	}
	return (1);
}

int	get_max_index(t_list *b_stack)
{
	int		res;
	int		index;
	long	*num;

	res = 0;
	index = 1;
	num = b_stack->content;
	b_stack = b_stack->next;
	while (b_stack)
	{
		if (*((long *)(b_stack->content)) > *num)
		{
			num = b_stack->content;
			res = index;
		}
		index++;
		b_stack = b_stack->next;
	}
	return (res);
}

int	get_index(size_t *stack, long *num)
{
	int	index;

	index = 0;
	while (stack)
	{
		if (*((long *)(stack->content)) == *num)
			return (index);
		stack = stack->next;
		index += 1;
	}
	return (index);
}

int	detect_half(t_list *b_stack, long *num)
{
	int	size;
	int	index;

	size = ft_lstsize(b_stack);
	if (num == NULL)
		index = check_max(b_stack) + 1;
	else
		index = get_index(b_stack, num) + 1;
	/*if (index == 1)
		return (0);*/
	if (size % 2 != 0)
	{
		if (index <= (size / 2) + 1)
			return (1);
		else
			return (-1);
	}
	if (index <= size / 2)
		return (1);
	return (-1);
}

void	move(t_list **a_stack, t_list **b_stack)
{
	long	*num;

	num = (*a_stack)->content;
	if (max_min(*num, *b_stack))
	{
		while (detect_half(*b_stack, NULL) == 1)
			rb(b_stack, 1);
		while (detect_half(*b_stacki, NULL) == 2)
			rrb(b_stack, 1);
		pb(a_stack, b_stack, 1);
	}
}

void	set_dir(t_directions *dir, t_list *head, t_list *node)
{
	if (detect_half(head, node->content) == 1)
		dir->a_dir = 1;
	else
		dir->a_dir = 2;
}


int	get_b_index(t_list *b_head, long *a_num)
{
	t_list	*current;
	int 	sub;
	int	res;
	int	index;

	if (max_min(*a_num, b_head))
		return (get_max_index(b_head));
	current = b_head->next;
	sub = *a_num - *((long *)(b_head->content));
	index = 0;
	res = 0;
	while (current)
	{
		if (*a_num - *((long *)(current->content)) < sub)
		{
			sub = *a_num - *((long *)(current->content));
			res = current;
		}
		index++;
		current = current->next;		
	}
	return (res);
}

int	ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

/*
void	calulate_steps(t_steps *steps, int size, int a_index, int b_index)
{
	int	a_best;
	int	b_best;
	int	best;
	
	int	r_greater;
	int	rr_greater;

	int	r_rr_smallest;

	steps->ra_steps = a_index;
	steps->rra_steps = size - a_index;
	steps->ra_steps = a_index;
	steps->rra_steps = size - a_index;

	if (ra_steps < rra_steps)
		a_best = ra_steps;
	else
		a_best = rra_steps;
	if (rb_steps < rrb_steps)
		b_best = rb_steps;
	else
		b_best = rrb_steps;
	
	best = a_best + b_best;
	
	if (ra_steps > rb_steps)
		r_greater = ra_steps;
	else
		r_greater = rb_steps;
	if (rra_steps > rrb_steps)
		rr_greater = rra_steps;
	else
		rr_greater = rrb_steps;

	if (r_greater < rr_greater)
		r_rr_smallest = r_greater;
	else
		r_rr_smallest = rr_greater;

	if (best < r_rr_grater)
		best = r_rr_grater;
}
*/

void    calulate_steps(t_steps *steps, int size, int a_index, int b_index)
{
        int     r_greater;
        int     rr_greater;	

        int     r_rr_smallest;



        steps->ra_steps = a_index;
        steps->rra_steps = size - a_index;
        steps->ra_steps = a_index;
        steps->rra_steps = size - a_index;

	int	best;

	if (ra_steps < rra_steps)
		steps->res->origs[0] = 1;
	else
		steps->res->origs[0] = -1;
	if (rb_steps < rrb_steps)
		steps->res->origs[1] = 1;
	else
		steps->res->origs[1] = -1;

	if (steps->res->origs[0] == 1)
	{
		if (steps->res->origs[1] == 1)
			best = steps->ra_steps - steps->rb_steps;
		else
			best = steps->ra_steps - steps->rrb_steps;
	}
	else if (steps->res->origs[0] == -1)
	{
		if (steps->res->origs[1] == 1)
			best = steps->rra_steps - steps->rb_steps;
		else
			best = steps->rra_steps - steps->rrb_steps;
	}


}



size_t	cheapest_num(t_list *a_stack, t_list *b_stack)
{
	int				size;
	int				moves;
	int	a_index;
	t_list			*a_head;
	t_list			*b_head;
	t_steps	steps;

	size = ft_lstsize(a_stack);
	a_head = a_stack;
	b_head = b_stack;
	a_index = 0;
	while (a_stack)
	{
		if ()
		//set_dir(&dir, a_head, a_stack);
		//calcolare l'index del numero di b da portare in cima;
	}
}

void	push_two(t_list **a_stack, t_list **b_stack)
{
	pb(a_stack, b_stack, 1);
	pb(a_stack, b_stack, 1);
}

void	start_algo(t_list **a_stack, t_list **b_stack)
{
	push_two(a_stack, b_stack);
	moves(a_stack, b_stack);
}
