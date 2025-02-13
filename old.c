#include "push_swap.h"

long	get_min(t_list *stack);

//non usata
int	detect_half(t_list *lst, long *num)
{
	int	size;
	int	index;

	size = ft_lstsize(lst);
	index = 0;
	while (lst)
	{
		if (*((long *)(lst->content)) == *num)
			break ;
		index++;
		lst = lst->next;
	}
	if (index <= size / 2)
		return (1);
	return (-1);
}


//non usata
long	get_num(int index, t_list *lst)
{
	while (index)
	{
		lst = lst->next;
		index--;
	}
	return (*((long *)(lst->content)));
}

void	print_lst(t_list *lst)
{
	ft_printf("--------------\n");
	while (lst)
	{
		ft_printf("%u\n", *((long *)(lst->content)));
		lst = lst->next;
	}
	ft_printf("--------------\n");
}
