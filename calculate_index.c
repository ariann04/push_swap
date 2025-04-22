/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblagoev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:26:14 by tblagoev          #+#    #+#             */
/*   Updated: 2025/04/22 21:53:10 by tblagoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*max_n(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (stack)
	{
		if (stack->content > tmp->content)
			tmp = stack;
		stack = stack->next;
	}
	return (tmp);
}

t_stack	*find_node(t_stack *stack, int pos)
{
	while (pos > 0)
	{
		stack = stack->next;
		pos--;
	}
	return (stack);
}

int	calculate_index(t_stack *stack, int number, char letter)
{
	int		index;
	int		index_low;
	t_stack	*min_node;
	t_stack	*max_node;

	index = 0;
	index_low = lowest_pos(&stack);
	min_node = find_node(stack, index_low);
	max_node = max_n(stack);
	while (stack)
	{
		if (stack->content == number && letter == 'b')
			return (index);
		if (stack->next && (stack->content < number
				&& stack->next->content > number) && letter == 'a')
			return (index + 1);
		if ((index == index_low) && letter == 'a' && min_node->content > number)
			return (index);
		if (stack == max_node && max_node->content < number)
			return (index + 1);
		stack = stack->next;
		index++;
	}
	return (0);
}
