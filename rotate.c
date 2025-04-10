#include "push_swap.h"

void	ra(t_stack **a, int print)
{
	t_stack	*tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = ft_lstlast(*a);
	(*a)->next = tmp;
	*a = tmp->next;
	tmp->next = NULL;
	if (print)
		write (1, "ra\n", 3);
}

void	rb(t_stack **b, int print)
{
	t_stack	*tmp;
	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	*b = ft_lstlast(*b);
	(*b)->next = tmp;
	*b = tmp->next;
	tmp->next = NULL;
	if (print)
		write (1, "ra\n", 3);
}

void	rr(t_stack **a, t_stack **b, int print)
{
	if (!*a || !(*a)->next || !b || !(*b)->next)
		return ;
	ra(a, 0);
	rb(b, 0);
	if (print)
		write(1, "rr\n", 3);
}
