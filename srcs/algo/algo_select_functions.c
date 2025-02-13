#include "push_swap.h"

void	few_push_all(t_list **a, t_list **b)
{
	long	a_num;
	int		index;

	while (*b)
	{
		a_num = calc_a_num((*b)->content, *a);
		index = get_index(*a, &a_num);
		rotate_a(a, index);
		pa(a, b, 1);
	}
}

void	few_cheapest_num(t_list **a, t_list **b)
{
	t_indexes	indxs;
	t_list		*a_head;
	t_list		*b_head;
	t_best		best;
	long		num;

	best_init(&best);
	pb(a, b, 1);
	pb(a, b, 1);
	while (ft_lstsize(*a) > 3)
	{
		a_head = *a;
		b_head = *b;
		while (*a)
		{
			indxs.a_index = get_index(a_head, (*a)->content);
			num = calc_b_num((*a)->content, b_head);
			indxs.b_index = get_index(b_head, &num);
			update_best(&best, &indxs, a_head, b_head);
			*a = (*a)->next;
		}
		*a = a_head;
		*b = b_head;
		rotate_and_push(&best, a, b);
		best_init(&best);
	}
	three_sort(a);
	few_push_all(a, b);
	rot_to_min(a, 1);
}

void	push_all(t_list **a, t_list **b)
{
	while (*b)
		pa(a, b, 1);
}

void	cheapest_num(t_list **a, t_list **b)
{
	t_indexes	indxs;
	t_list		*a_head;
	t_list		*b_head;
	t_best		best;
	long		num;

	best_init(&best);
	pb(a, b, 1);
	pb(a, b, 1);
	while (ft_lstsize(*a) > 0)
	{
		a_head = *a;
		b_head = *b;
		while (*a)
		{
			indxs.a_index = get_index(a_head, (*a)->content);
			num = calc_b_num((*a)->content, b_head);
			indxs.b_index = get_index(b_head, &num);
			update_best(&best, &indxs, a_head, b_head);
			*a = (*a)->next;
		}
		*a = a_head;
		*b = b_head;
		rotate_and_push(&best, a, b);
		best_init(&best);
	}
	push_all(a, b);
	rot_to_min(a, 1);
}

void	select_algo(t_list **a, t_list **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (size <= 7)
	{
		if (size == 2)
			two_sort(a);
		else if (size == 3)
			three_sort(a);
		else
			few_cheapest_num(a, b);
	}
	else
		cheapest_num(a, b);
}
