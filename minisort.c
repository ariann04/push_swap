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
		big_sort(a, b);
}

void	sort2(t_stack **a)
{
	sa(*a, 1);
}

void	sort3(t_stack **stack)
{
	if (checksorted(*stack))
		return ;
	if ((*stack)->content > (*stack)->next->content
			&& (*stack)->content > (*stack)->next->next->content)
	{
		if ((*stack)->next->content > (*stack)->next->next->content)
		{
			sa(*stack, 1);
			rra(stack, 1);
		}
		else
			ra(stack, 1);
	}
	else if ((*stack)->content > (*stack)->next->content)
		sa(*stack, 1);
	else if ((*stack)->content > (*stack)->next->next->content)
		rra(stack, 1);
	else
	{
		sa(*stack, 1);
		ra(stack, 1);
	}
}

void	sort4(t_stack **a, t_stack **b)
{
	int	min_pos;

	min_pos = lowest_pos(a);
	if (min_pos == 1)
		sa(*a, 1);
	else if (min_pos == 2)
	{
		rra(a, 1);
		rra(a, 1);
	}
	else if(min_pos == 3)
		rra(a, 1);
	pb(a, b);
	sort3(a);
	pa(a, b);
}

void	sort5(t_stack **a, t_stack **b)
{
	int	min_pos;

	min_pos = lowest_pos(a);
	if (min_pos == 1)
		sa(*a, 1);
	else if (min_pos == 2)
	{
		ra(a, 1);
		ra(a, 1);
	}
	else if(min_pos == 3)
	{
		rra(a, 1);
		rra(a, 1);
	}
	else if(min_pos == 4)
		rra(a, 1);
	pb(a, b);
	sort4(a, b);
	pa(a, b);
}
