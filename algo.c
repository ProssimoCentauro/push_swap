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

	res = 1;
	index = 2;
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

int	select_half(t_list *b_stack)
{
	int	size;
	int	max_index;

	size = ft_lstsize(b_stack);
	max_index = check_max(b_stack);
	if (max_index == 1)
		return (0);
	if (max_index <= size / 2)
		return (1);
	return (2);

}

void	moves(t_list **a_stack, t_list **b_stack)
{
	long	*num;

	num = (*a_stack)->content;
	if (max_min(*num, *b_stack))
	{
		while (select_half(*b_stack) == 1)
			rb(b_stack, 1);
		while (select_half(*b_stack) == 2) 
			rrb(b_stack, 1);
		pb(a_stack, b_stack, 1);
	}

}
/*
size_t	cheapest_num(t_list *a_stack, t_list *b_stack)
{
	int	i;
	int	size;
	
	i = 0;
	size = ft_lstsize(a_stack);

	while (i < size)
	{

	}
}*/

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
