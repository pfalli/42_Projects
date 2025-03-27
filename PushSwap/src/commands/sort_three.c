/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:50:29 by pfalli            #+#    #+#             */
/*   Updated: 2024/04/09 17:33:39 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest;

	biggest = find_max(*a);
	if (biggest == *a)
		ra(a, false);
	else if ((*a)->next == biggest)
		rra(a, false);
	if ((*a)->data > (*a)->next->data)
		sa(a, false);
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