/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblagoev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:29:00 by tblagoev          #+#    #+#             */
/*   Updated: 2025/04/22 21:45:27 by tblagoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	aux_rot(t_stack **a, t_stack **b, int *index_a, int *index_b)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(*a);
	size_b = ft_lstsize(*b);
	if ((*index_a) <= (size_a / 2) || (*index_b) <= (size_b / 2))
	{
		while (((*index_a) <= (size_a / 2) && ((*index_b) <= (size_b / 2)))
			&& (*index_a) != 0 && (*index_b) != 0)
		{
			(*index_a)--;
			(*index_b)--;
			rr(a, b);
		}
		while ((*index_a) <= (size_a / 2) && (*index_a) != 0)
		{
			(*index_a)--;
			ra(a, 1);
		}
		while ((*index_b) <= (size_b / 2) && (*index_b) != 0)
		{
			(*index_b)--;
			rb(b, 1);
		}
	}
}

void	aux_rev(t_stack **a, t_stack **b, int *index_a, int *index_b)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize(*a);
	size_b = ft_lstsize(*b);
	if ((*index_a) > (size_a / 2) || (*index_b) > (size_b / 2))
	{
		while (((*index_a) > (size_a / 2) && (*index_b) > (size_b / 2))
			&& ((*index_a) != size_a && (*index_b) != size_b))
		{
			(*index_a)++;
			(*index_b)++;
			rrr(a, b);
		}
		while (((*index_a) != size_a) && (*index_a) > (size_a / 2))
		{
			(*index_a)++;
			rra(a, 1);
		}
		while ((*index_b) > (size_b / 2) && (*index_b) != size_b)
		{
			(*index_b)++;
			rrb(b, 1);
		}
	}
}

void	organize(t_stack **a, t_stack **b, int element)
{
	int	index_a;
	int	index_b;
	int	size_a;
	int	size_b;

	index_a = calculate_index(*a, element, 'a');
	index_b = calculate_index(*b, element, 'b');
	size_a = ft_lstsize(*a);
	size_b = ft_lstsize(*b);
	if (index_a <= (size_a / 2) || index_b <= (size_b / 2))
		aux_rot(a, b, &index_a, &index_b);
	if (index_a > (size_a / 2) || index_b > (size_b / 2))
		aux_rev(a, b, &index_a, &index_b);
}
