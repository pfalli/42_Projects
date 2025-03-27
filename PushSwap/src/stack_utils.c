/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:45:29 by pfalli            #+#    #+#             */
/*   Updated: 2024/04/09 15:44:22 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	stack_len(t_stack_node *stack)
{
	int	count;

	count = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

t_stack_node	*find_last(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
	{
		stack = stack->next;
	}
	return (stack);
}

bool	stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack_node	*find_min(t_stack_node *stack)
{
	long			min;
	t_stack_node	*small_node;

	small_node = NULL;
	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->data < min)
		{
			min = stack->data;
			small_node = stack;
		}
		stack = stack->next;
	}
	return (small_node);
}

t_stack_node	*find_max(t_stack_node *stack)
{
	long			max;
	t_stack_node	*big;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->data > max)
		{
			max = stack->data;
			big = stack;
		}
		stack = stack->next;
	}
	return (big);
}
