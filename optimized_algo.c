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
	int		sub;
	int		res;
	int		index;

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
	return (b * -1);
}

void    t_steps_init(t_steps *steps)
{
    *steps->a_index = 0;
    *steps->b_index = 0;
}

int best_check(int best, t_steps steps)
{
    int a_min;
    int b_min;

    a_min = ft_min(steps.ra_steps, steps.rra_steps);
    b_min = ft_min(steps.rb_steps, steps.rrb_steps);

    if (a_min < 0)
    {
        if ((a_min * -1) < best || steps.ra_steps < best)
            return (0);
    }
    else
    {
        if (a_min < best || steps.rra_steps < best)
            return (0);
    }
    if (b_min < 0)
    {
        if ((b_min * -1) < best || steps.rb_steps < best)
            return (0);
    }
    else
    {
        if (b_min < best || steps.rrb_steps < best)
            return (0);
    }
    return (1);
}


void	calulate_steps(t_steps *steps, int a_size, int b_size)
{
	int	best;

	steps->ra_steps = a_index;
	steps->rra_steps = a_size - a_index;
	steps->rb_steps = b_index;
	steps->rrb_steps = b_size - b_index;
	
    if (steps->res->best != NULL)
    {
        if (best_check(steps->res_best, *steps))
            return ;
    }

    // calcolo il minore tra r ed rr di a e b
	if (ra_steps < rra_steps)
		steps->res->origs[0] = 1;
	else
		steps->res->origs[0] = -1;
	if (rb_steps < rrb_steps)
		steps->res->origs[1] = 1;
	else
		steps->res->origs[1] = -1;
	
    // li sommo per fare il best numero di mosse
	if (steps->res->origs[0] == 1)
	{
		if (steps->res->origs[1] == 1)
			best = steps->ra_steps + steps->rb_steps;
		else
			best = steps->ra_steps + steps->rrb_steps;
	}
	else if (steps->res->origs[0] == -1)
	{
		if (steps->res->origs[1] == 1)
			best = steps->rra_steps + steps->rb_steps;
		else
			best = steps->rra_steps + steps->rrb_steps;
	}
	
    // controllo che tra le altre 2 opzioni ce ne sia una migliore
	if (steps->res->orgis[0] == 1)
    {
		if (rra_steps < best)
		{
			best = rra_steps;
			steps->res->origs[0] = -1;
            steps->res->origs[1] = 0;
		}
    }
	else if (steps->res->orgis[0] == -1)
    {
        if (ra_steps < best)
		{
			best = ra_steps;
			steps->res->origs[0] = 1;
            steps->res->origs[1] = 0;
		}
    }
    if (steps->res->orgis[1] == 1)
    {
		if (rrb_steps < best)
		{
			best = rrb_steps;
			steps->res->origs[1] = -1;
            steps->res->origs[0] = 0;
		}
    }
    else if (steps->res->orgis[1] == -1)
    {
		if (rb_steps < best)
		{
			best = rb_steps;
			steps->res->origs[1] = 1;
            steps->res->origs[0] = 0;
		}
	}
    
    // aggiorno t_res
    steps->res->a_index = steps->a_index;
    steps->res->b_index = steps->b_index;
	steps->res->ra_steps = steps->ra_steps;
    steps->res->rra_steps = steps->rra_steps;
    steps->res->rb_steps = steps->rb_steps;
    steps->res->rrb_steps = steps->rrb_steps;
    steps->res->best = best;
}

size_t	cheapest_num(t_list *a_stack, t_list *b_stack)
{
	int		moves;
	t_list	*a_head;
	t_list	*b_head;
	t_steps	steps;

	a_head = a_stack;
	b_head = b_stack;
	t_steps_init(&steps);
    while (a_stack)
	{
        steps.b_index = get_b_index(b_head, 
                get_index(a_head, a_stack->content));
        calculate_steps(&steps, ft_lstsize(a_head),
                ft_lstsize(b_head));
        a_stack = a_stack->next;
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
