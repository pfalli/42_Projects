/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:50:11 by pfalli            #+#    #+#             */
/*   Updated: 2024/04/09 17:35:34 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	rev_rotate(t_stack_node **head)
{
	t_stack_node	*last_node;

	if (!(*head) || !(*head)->next)
		return ;
	last_node = find_last(*head);
	last_node->next = *head;
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	*head = last_node;
	last_node->next->prev = last_node;
}

void	rra(t_stack_node **a, bool print)
{
	rev_rotate(a);
	if (!print)
		ft_printf("rra\n");
}

void	rrb(t_stack_node **b, bool print)
{
	rev_rotate(b);
	if (!print)
		ft_printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b, bool print)
{
	rev_rotate(a);
	rev_rotate(b);
	if (!print)
		ft_printf("rrr\n");
}

//  main()
//  {
//      t_stack_node *head = malloc(sizeof(t_stack_node));
//      t_stack_node *second = malloc(sizeof(t_stack_node));
//      t_stack_node *third = malloc(sizeof(t_stack_node));
//
//      head->data = 1;
//      head->next = second;
//      head->prev = NULL;
//
//      second->data = 2;
//      second->next = third;
//      second->prev = head;
//
//      third->data = 3;
//      third->next = NULL;
//      third->prev = second;
//
//      printf("Before rotate: %d %d %d\n", head->data, second->data,
//	third->data);
//      rev_rotate(&head);
//      printf("After rotate: %d %d %d\n", head->data, head->next->data,
//	head->next->next->data );
//      rev_rotate(&head);
//      printf("After rotate: %d %d %d\n", head->data, head->next->data,
//	head->next->next->data );
//
//
//
//      return (0);
//  }
