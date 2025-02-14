#include "checker.h"

void    free_matrix(char ***matrix)
{
        char    **mat;
        size_t  i;

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

void    content_del(void *content)
{
        free(content);
}

void    free_and_exit(t_list **lst, void (*del)(void *), char *message)
{
        if (lst)
                ft_lstclear(lst, del);
        ft_printf("%s", message);
        exit(EXIT_FAILURE);
}
