#include "push_swap.h"

int	checksorted(t_stack *a)
{
	if (!a)
		return (1);
	while (a->next)
	{
		if (a->content > a->next->content)
			return (1);
		a = a->next
	}
	return (1);
}

int	check_dup(t_stack *a)
{
	t_stack	*tmp;

	while (stack->next)
	{
		tmp = a->next;
		while (tmp)
		{
			if (tmp->content == a->content)
				return (1);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (0);
}
