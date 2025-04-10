#include "push_swap.h"

int	checksorted(t_stack *a)
{
	if (!a)
		return (1);
	while (a->next)
	{
		if (a->content > a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}

int	check_dup(t_stack *a)
{
	t_stack	*tmp;

	while (a->next)
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

int	lowest_pos(t_stack **stack)
{
	t_stack	*tmp;
	int		min_content;
	int		min_index;
	int		index;

	tmp = *stack;
	if (tmp)
		min_content = (tmp)->content;
	index = 0;
	min_index = 0;
	while (tmp)
	{
		if ((tmp)->content < min_content)
		{
			min_index = index;
			min_content = tmp->content;
		}
		tmp = (tmp)->next;
		index++;
	}
	return (min_index);
}
