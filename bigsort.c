#include "push_swap.h"

void	sort_lowest(t_stack **a)
{
	int	size_a;
	int	lowest;

	size_a = ft_lstsize(*a);
	lowest = lowest_pos(a);
	if (lowest < (size_a / 2))
	{
		while (lowest != 0)
		{
			ra(a, 1);
			lowest--;
		}
		
	}
	else
	{
		while (lowest != size_a)
		{
			rra(a, 1);
			lowest++;
		}
	}
}

void	*best(t_stack **a, t_stack **b, t_stack *min_node, int size_b)
{
	int		index_b;
	t_stack	*current;
	int		min_cost;
	int		current_cost;

	index_b = 0;
	current = *b;
	min_cost = INT_MAX;
	while (index_b < size_b)
	{
		current_cost = calculate_cost(*a, *b, current, index_b);
		if (current_cost < min_cost)
		{
			min_node = current;
			min_cost = current_cost;
		}
		index_b++;
		current = (current)->next;
	}
	return (min_node);
}

void	big_sort(t_stack **a, t_stack **b)
{
	int		size_b;
	t_stack	*min_cost_node;

	while (ft_lstsize(*a) > 3)
		pb(a, b);
	sort3(a);
	size_b = ft_lstsize(*b);
	while (size_b != 0)
	{
		min_cost_node = best(a, b, min_cost_node, size_b);
		organize(a, b, min_cost_node->content);
		pa(a, b);
		size_b -= 1;
	}
	sort_lowest(a);
}
