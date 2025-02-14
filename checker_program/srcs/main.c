#include "checker.h"

int	main(int ac, char **av)
{
	t_list	*a_stack;
	t_list	*b_stack;

	a_stack = NULL;
	b_stack = NULL;
	if (ac == 1)
		exit(EXIT_FAILURE);
	parse_args(&a_stack, av);
    get_inputs(&a_stack, &b_stack);
    if (sorted(a_stack))
        ft_printf("OK\n");
    else
        ft_printf("KO\n");
    ft_lstclear(&a_stack, content_del);
	return (0);
}
