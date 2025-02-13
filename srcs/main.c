#include "algo.c"
#include "mov.c"
#include "push_swap.h"

void	print_stack(t_list *lst, char c)
{
	long	*num;

	ft_printf("|---STACK %c---|\n\n", c);
	while (lst)
	{
		num = lst->content;
		printf("%d\n", (int)*num);
		lst = lst->next;
	}
	ft_printf("\n|-------------|\n", c);
}

int	main(int ac, char **av)
{
	t_list	*a_stack;
	t_list	*b_stack;

	a_stack = NULL;
	b_stack = NULL;
	if (ac == 1)
		exit(EXIT_FAILURE);
	parse_args(&a_stack, av);
	if (!sorted(a_stack))
		select_algo(&a_stack, &b_stack);
	ft_lstclear(&a_stack, content_del);
	return (0);
}
