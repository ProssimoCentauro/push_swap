t_list  *lst_init(void)
{
        t_list  *lst;

        lst = (t_list *)malloc(sizeof(t_list));
        if (!lst)
                return (NULL);
        lst->next = NULL;
	lst->prev = NULL;
        return (element);
}

