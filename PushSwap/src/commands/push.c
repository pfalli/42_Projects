/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 10:49:32 by pfalli            #+#    #+#             */
/*   Updated: 2024/04/09 17:36:16 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*temp;

	if (!*src)
		return ;
	temp = (*src);
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	temp->prev = NULL;
	if (!*dst)
	{
		*dst = temp;
		temp->next = NULL;
	}
	else
	{
		temp->next = *dst;
		temp->next->prev = temp;
		*dst = temp;
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool print)
{
	push(a, b);
	if (!print)
		ft_printf("pa\n");
}

void	pb(t_stack_node **b, t_stack_node **a, bool print)
{
	push(b, a);
	if (!print)
		ft_printf("pb\n");
}

//  typedef struct s_stack_node
//  {
//      int value;
//      struct s_stack_node *next;
//      struct s_stack_node *prev;
//  } t_stack_node;
//
//  int main()
//  {
//      // Create two nodes for the source stack
//      t_stack_node *src = malloc(sizeof(t_stack_node));
//      src->value = 1;
//      src->next = malloc(sizeof(t_stack_node));
//      src->next->value = 2;
//      src->next->next = NULL;
//      src->next->prev = src;
//      src->prev = NULL;
//
//      // Create an empty destination stack
//      t_stack_node *dst = NULL;
//
//      // Print the source stack before the push
//      printf("Source stack before push: ");
//      t_stack_node *current = src;
//      while (current != NULL)
//      {
//          printf("%d ", current->value);
//          current = current->next;
//      }
//      printf("\n");
//
//      // Call the push function
//      push(&dst, &src);
//
//      // Print the source stack after the push
//      printf("Source stack after push: ");
//      current = src;
//      while (current != NULL)
//      {
//          printf("%d ", current->value);
//          current = current->next;
//      }
//      printf("\n");
//
//      // Print the destination stack after the push
//      printf("Destination stack after push: ");
//      current = dst;
//      while (current != NULL)
//      {
//          printf("%d ", current->value);
//          current = current->next;
//      }
//      printf("\n");
//
//      return (0);
//  }