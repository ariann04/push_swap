#include "push_swap.h"

void	cases(t_stack **a, t_stack **b)
{
	if ((*a)->next->next == NULL)
		sort2(a);
	else if (ft_lstsize(*a) == 3)
		sort3(a);
	else if (ft_lstsize(*a) == 4)
		sort4(a, b);
	else if (ft_lstsize(*a) == 5)
		sort5(a, b);
	else
		general_algorithm(a, b);
}

void	sort2(t_stack **a)
{
	sa(a, 1);
}

void	sort3(t_stack **a)
{
	if (check_sorted(*a))
		return ;
	if (ft_min(*a) == (*a)->nbr)
	{
		rra(a, 1);
		sa(a, 1);
	}
	else if (ft_max(*a) == (*a)->nbr)
	{
		ra(a, 1);
		if (!check_sorted(*a))
			sa(a, 1);
	}
	else
	{
		if (find_index(*a, ft_max(*a)) == 1)
			rra(a, 1);
		else
			sa(a, 1);
	}
}

void	sort4(t_stack **a, t_stack **b)
{
	if (ft_min(*a) == 1)
		sa(a, 1);
	else if (ft_min(*a) == 2)
	{
		rra(a, 1);
		rra(a, 1);
	}
	else if(ft_min(*a) == 3)
		rra(a, 1);
	pb(a, b);
	sort3(a);
	pa(a, b);
}

void	sort5(t_stack **a, t_stack **b)
{}
