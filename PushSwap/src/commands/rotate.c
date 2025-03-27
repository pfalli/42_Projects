/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:50:02 by pfalli            #+#    #+#             */
/*   Updated: 2024/04/09 17:35:02 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (!(*stack) || !(*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stack_node **a, bool print)
{
	rotate(a);
	if (!print)
		ft_printf("ra\n");
}

void	rb(t_stack_node **b, bool print)
{
	rotate(b);
	if (!print)
		ft_printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b, bool print)
{
	rotate(a);
	rotate(b);
	if (!print)
		ft_printf("rr\n");
}

//  int main()
//      {
//          t_stack_node *head = malloc(sizeof(t_stack_node));
//          t_stack_node *second = malloc(sizeof(t_stack_node));
//          t_stack_node *third = malloc(sizeof(t_stack_node));
//
//          head->data = 1;
//          head->next = second;
//          head->prev = NULL;
//
//          second->data = 2;
//          second->next = third;
//          second->prev = head;
//
//          third->data = 3;
//          third->next = NULL;
//          third->prev = second;
//
//          printf("Before rotate: %d %d %d\n", head->data, second->data,
//	third->data);
//          rotate(&head);
//          printf("After rotate: %d %d %d\n", head->data, head->next->data,
//	head->next->next->data );
//          rotate(&head);
//          printf("After rotate: %d %d %d\n", head->data, head->next->data,
//	head->next->next->data );
//
//
//
//
//          return (0);
//      }