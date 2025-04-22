/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblagoev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:26:00 by tblagoev          #+#    #+#             */
/*   Updated: 2025/04/22 21:39:18 by tblagoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	aux_rotate(int *index_a, int *index_b, int size_a, int size_b)
{
	int	move;

	move = 0;
	while (((*index_a) <= (size_a / 2) && (*index_b) <= (size_b / 2))
		&& (*index_a) != 0 && (*index_b) != 0)
	{
		(*index_a)--;
		(*index_b)--;
		move++;
	}
	while ((*index_a) <= (size_a / 2) && (*index_a) != 0)
	{
		(*index_a)--;
		move++;
	}
	while ((*index_b) <= (size_b / 2) && (*index_b) != 0)
	{
		(*index_b)--;
		move++;
	}
	return (move);
}

int	aux_reverse(int *index_a, int *index_b, int size_a, int size_b)
{
	int	move;

	move = 0;
	while ((*index_a) > (size_a / 2) && (*index_b) > (size_b / 2)
		&& (*index_a) != size_a && (*index_b) != size_b)
	{
		(*index_a)++;
		(*index_b)++;
		move++;
	}
	while ((*index_a) > (size_a / 2) && (*index_a) != size_a)
	{
		(*index_a)++;
		move++;
	}
	while ((*index_b) > (size_b / 2) && (*index_b) != size_b)
	{
		(*index_b)++;
		move++;
	}
	return (move);
}

int	calculate_cost(t_stack *a, t_stack *b, t_stack *node, int inb)
{
	int	index_a;
	int	movements;
	int	size_a;
	int	size_b;

	index_a = calculate_index(a, node->content, 'a');
	size_a = ft_lstsize(a);
	size_b = ft_lstsize(b);
	movements = 0;
	if (index_a <= (size_a / 2) || inb <= (size_b / 2))
		movements += aux_rotate(&index_a, &inb, size_a, size_b);
	if (index_a > (size_a / 2) || inb > (size_b / 2))
		movements += aux_reverse(&index_a, &inb, size_a, size_b);
	return (movements);
}
