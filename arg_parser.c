#include "mov.c"
#include "push_swap.h"

void	free_matrix(char ***matrix)
{
	char	**mat;
	size_t	i;

	mat = *matrix;
	i = 0;
	while (mat[i])
	{
		free(mat[i]);
		mat[i++] = NULL;
	}
	free(mat);
	mat = NULL;
}

void	content_del(void *content)
{
	free(content);
}

void	free_and_exit(t_list **lst, void (*del)(void *), char *message)
{
	if (lst)
		ft_lstclear(lst, del);
	ft_printf("%s", message);
	exit(EXIT_FAILURE);
}

int	check_args(char **args)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		if (args[i][j] == '+' || args[i][j] == '-')
			j++;
		if (args[i][j] == '\0')
			return (0);
		while (args[i][j] >= '0' && args[i][j] <= '9' && args[i][j] != '\"')
			j++;
		if (args[i][j] != '\0')
			return (0);
		i++;
	}
	if (!args[0])
		return (0);
	return (1);
}

int	check_duplicates(t_list *lst)
{
	long	*num;
	t_list	*to_check;
	t_list	*current;

	if (!lst->next)
		return (1);
	to_check = lst;
	while (to_check)
	{
		current = lst;
		num = to_check->content;
		while (current)
		{
			if (to_check != current)
			{
				if (*num == *((long *)(current->content)))
					return (0);
			}
			current = current->next;
		}
		to_check = to_check->next;
	}
	return (1);
}

long	ft_atol(char *nptr)
{
	int		sign;
	long	num;

	sign = 1;
	num = 0;
	while ((*nptr == ' ') || ((*nptr >= 9) && (*nptr <= 13)))
		nptr++;
	if ((*nptr == '+') || (*nptr == '-'))
	{
		if (*nptr == '-')
			sign = -sign;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		num = (num * 10) + (*nptr - '0');
		nptr++;
	}
	return (num * sign);
}

void	create_list(t_list **lst, char ***matrix)
{
	t_list	*node;
	long	*num;
	char	**mat;
	size_t	i;

	mat = *matrix;
	i = 0;
	while (mat[i])
	{
		num = (long *)malloc(sizeof(long));
		if (!num)
			free_and_exit(lst, content_del, MALLOC_ERROR);
		*num = ft_atol(mat[i]);
		// da controllare min int senza '-'
		if (*num > 2147483647)
		{
			free_matrix(matrix);
			free_and_exit(lst, content_del, INPUT_ERROR);
		}
		node = ft_lstnew(num);
		if (!node)
			free_and_exit(lst, content_del, MALLOC_ERROR);
		ft_lstadd_back(lst, node);
		i++;
	}
}

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

t_list	*find_max(t_list *lst)
{
	long	*num;
	long	*num2;
	t_list	*res;

	if (!lst)
		return (NULL);
	res = lst;
	lst = lst->next;
	while (lst)
	{
		num = (long *)res->content;
		num2 = (long *)lst->content;
		if (*num2 > *num)
			res = lst;
		lst = lst->next;
	}
	return (res);
}

void	three_sort(t_list **lst)
{
	long	*num;
	long	*num2;
	t_list	*max;

	max = find_max(*lst);
	if (max == *lst)
		ra(lst, 1);
	else if (max == (*lst)->next)
		rra(lst, 1);
	num = (*lst)->content;
	num2 = (*lst)->next->content;
	if (*num > *num2)
		sa(lst, 1);
}

void	parse_args(t_list **a_stack, char **av)
{
	size_t	i;
	char	**matrix;

	i = 1;
	while (av[i])
	{
		matrix = ft_split(av[i++], ' ');
		if (!matrix)
			free_and_exit(a_stack, content_del, MALLOC_ERROR);
		if (!check_args(matrix))
		{
			free_matrix(&matrix);
			free_and_exit(a_stack, content_del, INPUT_ERROR);
		}
		create_list(a_stack, &matrix);
		free_matrix(&matrix);
	}
}

int	main(int ac, char **av)
{
	t_list	*a_stack;
	t_list	*b_stack;

	a_stack = NULL;
	b_stack = NULL;
	if (ac == 1)
		free_and_exit(&a_stack, content_del, INPUT_ERROR);
	parse_args(&a_stack, av);
	if (check_duplicates(a_stack) == 0)
		free_and_exit(&a_stack, content_del, INPUT_ERROR);
	print_stack(a_stack, 'A');
	print_stack(b_stack, 'B');
	pa(&a_stack, &b_stack, 1);
	print_stack(a_stack, 'A');
	print_stack(b_stack, 'B');
	ft_lstclear(&a_stack, content_del);
	return (0);
}
