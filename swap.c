#include "push_swap.h"

void	sa(t_stack *a, int print)
{
	int	tmp;

	if (!a || !(a)->next)
		return ;
	tmp = (a)->content;
	(a)->content = (a)->next->content;
	(a)->next->content = tmp;
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_stack *b, int print)
{
	sa(b, 0);
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b, int print)
{
	sa(a, 0);
	sb(b, 0);
	if (print)
		write(1, "ss\n", 3);
}
