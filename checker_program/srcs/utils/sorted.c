#include "checker.h"

int	sorted(t_list *stack)
{
	long	num;

	if (ft_lstsize(stack) == 0)
		return (0);
	num = *((long *)(stack->content));
	stack = stack->next;
	while (stack)
	{
		if (num > *((long *)(stack->content)))
			return (0);
		num = *((long *)(stack->content));
		stack = stack->next;
	}
	return (1);
}
