int     get_index(t_list *lst, long *num)
{
        int     index;

        index = 0;
        while (lst)
        {
                if (*((long *)(lst->content)) == *num)
                        break ;
                index++;
                lst = lst->next;
        }
        return (index);
}

int     ft_abs(int num)
{
        if (num < 0)
                return (num * -1);
        return (num);
}

int     ft_max(int a, int b)
{
        if (a >= b)
                return (a);
        return (b);
}

int     same_sign(int a, int b)
{
        if (a < 0 && b < 0)
                return (1);
        if (a >= 0 && b >= 0)
                return (1);
        return (0);
}

