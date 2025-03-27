/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_nodes_a_to_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:47:59 by pfalli            #+#    #+#             */
/*   Updated: 2024/04/09 17:31:47 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	set_index(t_stack_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

static void	set_target_node_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*target_node_temp;
	t_stack_node	*current_b;
	long			best_matched;

	while (a)
	{
		best_matched = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->data < a->data && current_b->data > best_matched)
			{
				best_matched = current_b->data;
				target_node_temp = current_b;
			}
			current_b = current_b->next;
		}
		if (best_matched == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target_node_temp;
		a = a->next;
	}
}

static void	set_on_top_cost(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->on_top_cost = a->index;
		if (!(a->above_median))
			a->on_top_cost = len_a - (a->index);
		if ((a->target_node->above_median))
			a->on_top_cost += a->target_node->index;
		else
			a->on_top_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}

void	set_cheapest(t_stack_node *stack)
{
	long			cheapest_value;
	t_stack_node	*node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->on_top_cost < cheapest_value)
		{
			cheapest_value = stack->on_top_cost;
			node = stack;
		}
		stack = stack->next;
	}
	node->cheapest = true;
}

void	info_nodes_a(t_stack_node *a, t_stack_node *b)
{
	set_index(a);
	set_index(b);
	set_target_node_a(a, b);
	set_on_top_cost(a, b);
	set_cheapest(a);
}
