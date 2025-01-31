#include "push_swap.h"

void	sa(t_list **a, int flag)
{
	t_list	*temp;

	if (!*a || !(*a)->next)
		return ;
	temp = (*a)->next;
	(*a)->next = temp->next;
	temp->next = *a;
	*a = temp;
	if (flag == 1)
		ft_printf("sa\n");
}

void	sb(t_list **b, int flag)
{
	t_list	*temp;

	if (!*b || !(*b)->next)
		return ;
	temp = (*b)->next;
	(*b)->next = temp->next;
	temp->next = *b;
	*b = temp;
	if (flag == 1)
		ft_printf("sb\n");
}

void	ss(t_list **a, t_list **b)
{
	sa(a, 0);
	sb(b, 0);
	ft_printf("ss\n");
}

void	pa(t_list **a, t_list **b, int flag)
{
	t_list	*temp;

	if (!b || !*b)
		return ;
	temp = (*b)->next;
	(*b)->next = *a;
	*a = *b;
	*b = temp;
	if (flag == 1)
		ft_printf("pa\n");
}

void	pb(t_list **a, t_list **b, int flag)
{
	t_list	*temp;

	if (!a || !*a)
		return ;
	temp = (*a)->next;
	(*a)->next = *b;
	*b = *a;
	*a = temp;
	if (flag == 1)
		ft_printf("pb\n");
}

void	ra(t_list **a, int flag)
{
	t_list	*temp;

	if (!a || !*a || !(*a)->next)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = NULL;
	ft_lstadd_back(a, temp);
	if (flag == 1)
		ft_printf("ra\n");
}

void	rb(t_list **b, int flag)
{
	t_list	*temp;

	if (!b || !*b || !(*b)->next)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = NULL;
	ft_lstadd_back(b, temp);
	if (flag == 1)
		ft_printf("ra\n");
}

void	rr(t_list **a, t_list **b)
{
	ra(a, 0);
	rb(b, 0);
	ft_printf("rr\n");
}

void	rra(t_list **a, int flag)
{
	t_list	*temp;
	t_list	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	temp = *a;
	while (temp->next->next)
		temp = temp->next;
	last = temp->next;
	temp->next = NULL;
	last->next = *a;
	*a = last;
	if (flag == 1)
		ft_printf("rra\n");
}

void	rrb(t_list **b, int flag)
{
	t_list	*temp;
	t_list	*last;

	if (!b || !*b || !(*b)->next)
		return ;
	temp = *b;
	while (temp->next->next)
		temp = temp->next;
	last = temp->next;
	temp->next = NULL;
	last->next = *b;
	*b = last;
	if (flag == 1)
		ft_printf("rrb\n");
}

void	rrr(t_list **a, t_list **b)
{
	rra(a, 0);
	rra(b, 0);
	ft_printf("rrr\n");
}
