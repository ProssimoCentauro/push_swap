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
        if (args[i][j] == '\0')
            return (0);
        while (args[i][j] >= '0' && args[i][j] <= '9')
            j++;
        if (args[i][j] != '\0')
            return (0);
        i++;
    }
    return (1);
}

int    check_duplicates(t_list *lst)
{
    long    *num;
    t_list  *to_check;
    t_list  *current;
    
    if (!lst->next)
        return (1);
    to_check = lst;
    while (to_check)
    {
        current = lst;
        num = to_check->content;
        while(current)
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
    if (check_duplicates(lst) == 0)
        exit(EXIT_FAILURE);
    print_stack(lst, 'A');
	return (0);
}
