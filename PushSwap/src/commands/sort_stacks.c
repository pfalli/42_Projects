/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:50:32 by pfalli            #+#    #+#             */
/*   Updated: 2024/04/09 17:34:19 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	both_rev_rotate(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b, false);
	set_index(*a);
	set_index(*b);
}

static void	both_rotate(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b, false);
	set_index(*a);
	set_index(*b);
}

static void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	// cheapest_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	// if (!cheapest_node)
	// 	return ;
	cheapest_node = get_cheapest_node(*a);
	printf("Cheap: %d\n", cheapest_node->data);
	print_stack(*a);
	print_stack(*b);
	if (cheapest_node == NULL)
		return ;
	// in case both rotate
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		both_rotate(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		both_rev_rotate(a, b, cheapest_node);
	put_to_top(a, cheapest_node, 'a');
	put_to_top(b, cheapest_node->target_node, 'b');
	pb(b, a, false);
	// free(cheapest_node);
}

static void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	put_to_top(a, (*b)->target_node, 'a');
	pa(a, b, false);
}

static void	min_on_top(t_stack_node **a)
{
	while ((*a)->data != find_min(*a)->data)
	{
		if (find_min(*a)->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	length_a;

	length_a = stack_len(*a);
	if (length_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	if (length_a-- > 3 && !stack_sorted(*a))
		pb(b, a, false);
	while ((length_a-- > 3 && !stack_sorted(*a)))
	{
		info_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	// print_stack(*a);
	// printf("Stack b");
	// print_stack(*b);
	// exit(0);
	sort_three(a);
	while (*b)
	{
		info_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	set_index(*a);
	min_on_top(a);
}

//  t_stack_node *create_new_node(int num)
//  {
//      t_stack_node *node = (t_stack_node*)malloc(sizeof(t_stack_node));
//
//      node->data = num;
//      node->next = NULL;
//      return(create_new_node);
//  }
//
//  void *push(t_stack_node **stack, int newdata)
//  {
//      t_stack_node *another_node = create_new_node(newdata);
//
//      another_node->next = (*stack);
//      (*stack) = create_new_node;
//  }
//
//  int main(void)
//  {
//      t_stack_node *stack = NULL;
//
//      // Push elements to the stack
//      push(&stack, 3);
//      push(&stack, 1);
//      push(&stack, 2);
//
//      // Call the sort_three function
//      sort_three(&stack);
//
//      // Print the sorted stack
//      t_stack_node *temp = stack;
//      while(temp != NULL)
//      {
//          printf("%d ", temp->data);
//          temp = temp->next;
//      }
//
//      return (0);
//  }