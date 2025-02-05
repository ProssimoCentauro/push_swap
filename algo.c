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

int	check_max(t_list *b_stack)
{
	int	res;
	int	index;
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

int get_index(size_t *stack, long *num)
{
    int index;

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
            return (2);
    }
    if (index <= size / 2)
		return (1);
    return (2);
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

void    set_dir(t_directions *dir, t_list *head, t_list *node)
{
        if (detect_half(head, node->content) == 1)
            dir->a_dir = 1;
        else
            dir->a_dir = 2;
}

size_t	cheapest_num(t_list *a_stack, t_list *b_stack)
{
	int	size;
    int moves;
    t_list  *a_head;
    t_list  *b_head;
    t_directions    dir;

	size = ft_lstsize(a_stack);
	a_head = a_stack;
    b_head = b_stack;
    while (a_stack)
	{
        set_dir(&dir, a_head, a_stack);
        //controllare se è il numero massimo
        //se si calcolare index del numero massimo di b
        //altrimenti calcolare index del numero sopra cui dovrebbe andare il numero di a
        //vedere se le direzioni sono uguali
        //sottrarre per calcolare le mosse che possono avvenire insieme
        //spostare i numeri in prima posizione
        //pushare in b
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
