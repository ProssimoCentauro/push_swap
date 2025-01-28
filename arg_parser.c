#include "push_swap.h"

int	check_args(char **args)
{
    size_t  i;
    size_t  j;

    i = 0;
	while (args[i])
    {
        j = 0;
        if (args[i][j] == '+' || args[i][j]== '-')
            j++;
        while (args[i][j] >= '0' && args[i][j] <= '9')
            j++;
        if (args[i][j] != '\0')
            return (0);
        i++;
    }
    return (1);
}

void check_duplicates(t_list *lst)
{
    long arr[1000];
    long *num;
    size_t  i;

    i = 0;
    while (arr[i])
        arr[i++] = 0;
    while (lst)
    {
        num = lst->content;
        if (arr[*num] == 0)
            arr[*num] = 1;
        else if (arr[*num] == 1)
            exit(EXIT_FAILURE);
        lst = lst->next;
    }
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

void	create_list(t_list **lst, char **matrix)
{
	t_list	*node;
	long	*num;

	while (*matrix)
	{
		num = (long *)malloc(sizeof(int));
		if (!num)
			exit(EXIT_FAILURE);
		*num = ft_atol(*matrix);
        if (*num > 2147483647)
            exit(EXIT_FAILURE);
		node = ft_lstnew(num);
		if (!node)
			exit(EXIT_FAILURE);
		ft_lstadd_back(lst, node);
		matrix++;
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

int	main(int ac, char **av)
{
    (void)ac;
	t_list	*lst;
	char	**matrix;
	size_t	i;
	size_t	j;

    lst = NULL;
	i = 1;
	while (av[i])
	{
		j = 0;
		matrix = ft_split(av[i++], ' ');
		if (!matrix)
			exit(EXIT_FAILURE);
        if (!check_args(matrix))
			exit(EXIT_FAILURE);
		create_list(&lst, matrix);
		while (matrix[j])
		{
			free(matrix[j]);
			matrix[j++] = NULL;
		}
		free(matrix);
		matrix = NULL;
	}
    check_duplicates(lst);
	print_stack(lst, 'A');
	return (0);
}
