void	sa(t_list *lst)
{
	long	tmp;

	if (!lst || !*lst || !*lst->next)
		return ;
	tmp = lst->next->num;
	lst->next->num = lst->num;
	lst->num = tmp;
	ft_printf("sa\n");
}

void	sb(t_list *lst)
{
	long	tmp;

	if (!lst || !*lst || !*lst->next)
		return ;
	tmp = lst->next->num;
	lst->next->num = lst->num;
	lst->num = tmp;
	ft_printf("sb\n");
}

void	ss(t_list *lst)
{
	long	tmp;

	if (!lst || !*lst || !*lst->next)
		return ;
	tmp = lst->next->num;
	lst->next->num = lst->num;
	lst->num = tmp;
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

	if (!a || !*a || !(*b)->next)
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

	if (!b || !*bi || !(*b)->next)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = NULL;
	ft_lstadd_back(b, temp);
        ft_printf("ra\n");
}

void	rr(t_list **a, t_list **b, void (*del)(void *))
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

void    rra(t_list **a)
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
