#include "push_swap.h"

int detect_half(t_list *lst, long *num)
{
    int size = ft_lstsize(lst);
    int index;

    index = 0;
    while (lst)
    {
        if (*((long *)(lst->content)) == *num)
            break;
        index++;
        lst = lst->next;
    }
    if (index <= size / 2)
        return (1);
    return (-1);
}

void    move(t_list **a, t_list **b)
{
    
}

int ft_max(int a, int b)
{
    if (a >= b)
        return (a);
    return (b);
}

int same_sign(int a, int b)
{
    if (a < 0 && b < 0)
        return (1);
    if (a >= 0 && b >= 0)
        return (1);
    return (0);
}

int ft_abs(int num)
{
    //controllare min int;
    if (num < 0)
        return (num * -1);
    return(num);
}

long	get_num(int index, t_list *lst)
{
	while(index)
	{
		lst = lst->next;
		index--;
	}
	return (*((long *)(lst->content)));
}

void update_best(t_best *best, t_indexes *indxs, t_list *a, t_list *b)
{
    int ra;
    int rb;
    int rra;
    int rrb;
    t_best  tmp_best;

    ra = indxs->a_index;
    rb = indxs->b_index;
    rra = indxs->a_index - ft_lstsize(a);
    rrb = indxs->b_index - ft_lstsize(b);

	ft_printf("ra: %n\n", ra);
	ft_printf("rb: %n\n", rb);
	ft_printf("rra: %n\n", rra);
	ft_printf("rrb: %n\n", rrb);
	exit(EXIT_SUCCESS);
    if (ra < (rra * -1))
        tmp_best.a_moves = ra;
    else
        tmp_best.a_moves = rra;
    if (rb < (rrb * -1))
        tmp_best.b_moves = rb;
    else
        tmp_best.b_moves = rrb;


    //calcolo numero totale di mosse
    if (same_sign(tmp_best.a_moves, tmp_best.b_moves))
        tmp_best.moves = ft_max(ft_abs(tmp_best.a_moves),
                ft_abs(tmp_best.b_moves));
    else
    {
        //in teoria
        //rb = a b_index
        if (tmp_best.a_moves >= 0 && tmp_best.a_moves >= rb)
            tmp_best.moves = tmp_best.a_moves;
        //rrb uguale a b_moves
        else if (tmp_best.a_moves < 0 && tmp_best.a_moves <= rrb)
            tmp_best.moves = ft_abs(tmp_best.a_moves);
        else
        {
            tmp_best.moves = ft_abs(tmp_best.a_moves) +
            ft_abs(tmp_best.b_moves); 
        }
    }
//controllare se è il best
    if (tmp_best.moves < best->moves)
    {
	    best->rb = rb;
	    best->rrb = rrb;
        best->a_index = indxs->a_index;
        best->b_index = indxs->b_index;
        best->a_moves = tmp_best.a_moves;
        best->b_moves = tmp_best.b_moves;
        best->moves = tmp_best.moves;
    }
}

int get_index(t_list *lst, long *num)
{
    int size = ft_lstsize(lst);
    int index;

    index = 0;
    while (lst)
    {
        if (*((long *)(lst->content)) == *num)
            break;
        index++;
        lst = lst->next;
    }
    return (index);
}

//calcola quale numero prendere a seconda del numero in a 
long calc_b_num(long *a_num, t_list *b)
{
    long    sub;
    long    res;
    
    sub = *a_num - *((long *)(b->content));
    res = *((long *)(b->content));
    b = b->next;
    while (b)
    {
        if (*a_num - *((long *)(b->content)) < sub)
        {
            sub = *a_num - *((long *)(b->content));
            res = *((long *)(b->content));
        }
        b = b->next;
    }
    return (res);
}


void move_same_sign(t_best *best, t_list **a, t_list **b)
{
        if (best->a_moves > 0)
        {
            while (best->a_moves > 0 || best->b_moves > 0)
            {
		    ft_printf("%i\n", best->a_moves);
                rr(a, b);
                best->a_moves -= 1;
                best->b_moves -= 1;
            }
            while (best->a_moves > 0)
            {
                best->a_moves -= 1;
                ra(a, 1);
            }
            while (best->b_moves > 0)
            {
                best->b_moves -= 1;
                rb(b, 1);
            }
        }
        else if (best->a_moves < 0)
        {
            while (best->a_moves < 0 || best->b_moves < 0)
            {
                rr(a, b);
                best->a_moves += 1;
                best->b_moves += 1;
            }
            while (best->a_moves < 0)
            {
                best->a_moves += 1;
                ra(a, 1);
            }
            while (best->b_moves < 0)
            {
                best->b_moves += 1;
                rb(b, 1);
            }
        }
}

void	move_case_1(t_best *best, t_list **a, t_list **b)
{
	while (best->rb > 0)
	{
		rr(a, b);
		best->rb -= 1;
		best->moves -= 1;
	}
	while (best->moves > 0)
	{
		ra(a, 1);
		best->moves -= 1;
	}
}

void	move_case_2(t_best *best, t_list **a, t_list **b)
{
	while (best->rrb < 0)
	{
		rrr(a, b);
		best->rrb += 1;
		best->moves -= 1;
	}
	while (best->moves > 0)
	{
		rra(a, 1);
		best->moves -= 1;
	}
}

void	move_case_3(t_best *best, t_list **a, t_list **b)
{
	if (best->a_moves < 0)
	{
		while (best->a_moves)
		{
			rra(a, 1);
			best->a_moves += 1;
		}
	}
	else if (best->a_moves >= 0)
	{
		while (best->a_moves)
		{
			ra(a, 1);
			best->a_moves -= 1;
		}
	}
	if (best->b_moves < 0)
	{
		while (best->b_moves)
		{
			rrb(b, 1);
			best->b_moves += 1;
		}
	}
	else if (best->b_moves >= 0)
	{
		while (best->b_moves)
		{
			rb(b, 1);
			best->b_moves -= 1;
		}
	}
}

void    rotate_and_push(t_best *best, t_list **a, t_list **b)
{
    if (same_sign(best->a_moves, best->b_moves))
	    move_same_sign(best, a, b);
    else if (best->a_moves >= 0 && best->a_moves >= best->rb)
	    move_case_1(best, a, b);
    else if (best->a_moves < 0 && best->a_moves <= best->rrb)
	    move_case_2(best, a, b);
    else
	    move_case_3(best, a, b);
    pb(a, b, 1);
}

void    cheapest_num(t_list **a, t_list **b)
{
    t_indexes   indxs;
    t_list *a_head;
    t_list *b_head;
    t_best  best;
	long	num;

    a_head = *a;
    pb(a, b, 1);
    pb(a, b, 1);
    b_head = *b;
    while (ft_lstsize(*a) > 3)
    {
        while (*a)
        {
            indxs.a_index = get_index(a_head, (*a)->content);
            num = calc_b_num((*a)->content, b_head);
	    indxs.b_index = get_index(b_head, &num);
            update_best(&best, &indxs, a_head, b_head);
            *a = (*a)->next;
        }
        //quando la lista viene esaminata tutta, bisogna ruotare le due lista di tot e pushare l'lelemento. Fatto questo va riesaminata tutta per rivenedere il nuovo best elemento da pushare, il puntatore come va gestito?
    	*a = a_head;
	rotate_and_push(&best, a, b);
    }
    //reset best;
}
