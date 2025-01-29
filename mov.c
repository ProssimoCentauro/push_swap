void	sa(t_list **a)
{
    t_list  *temp;
    
    if (!*a || !(*a)->next)
	    return ;
    temp = (*a)->next;
    (*a)->next = temp->next;
    temp->next = *a;
    ft_printf("sa\n");
}

void	sb(t_list **b)
{
    t_list  *temp;
    
    if (!*b || !(*b)->next)
	    return ;
    temp = (*b)->next;
    (*b)->next = temp->next;
    temp->next = *b;

    ft_printf("sb\n");
}

void	ss(t_list **a, t_list **b)
{
	sa(a);
	sb(b);
	ft_printf("ss\n");
}

void	pa(t_list **a, t_list **b)
{
	t_list	*temp;
	
	if (!b || !*b)
		return ;
	temp = (*b)->next;
	(*b)->next = *a;
	*a = *b;
	*b = temp;
	ft_printf("pa\n");
}

void	pb(t_list **a, t_list **b)
{
	t_list	*temp;
	
	if (!a || !*a)
		return ;
	temp = (*a)->next;
	(*a)->next = *b;
	*b = *a;
	*a = temp;
	ft_printf("pb\n");
}

void	ra(t_list **a)
{
	t_list	*temp;

	if (!a || !*a || !(*a)->next)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = NULL;
	ft_lstadd_back(a, temp);
    ft_printf("ra\n");
}

void	rb(t_list **b)
{
	t_list	*temp;

	if (!b || !*b || !(*b)->next)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = NULL;
	ft_lstadd_back(b, temp);
    ft_printf("ra\n");
}

void	rr(t_list **a, t_list **b)
{
	ra(a);
	rb(b);
	ft_printf("rr\n");
}

void    rra(t_list **a)
{
        t_list  *temp;
        t_list  *last;

        if (!a || !*a || !(*a)->next)
                return ;
        temp = *a;
        while (temp->next->next)
                temp = temp->next;
        last = temp->next;
        temp->next = NULL;
        last->next = *a;
        *a = last;
        ft_printf("rrb\n");
}

void    rrb(t_list **b)
{
        t_list  *temp;
        t_list  *last;

        if (!b || !*b || !(*b)->next)
                return ;
        temp = *b;
        while (temp->next->next)
                temp = temp->next;
        last = temp->next;
        temp->next = NULL;
        last->next = *b; 
        *b = last; 
        ft_printf("rrb\n");
}

void    rrr(t_list **a, t_list **b)
{
	rra(a);
	rra(b);
	ft_printf("rrr\n");
}
