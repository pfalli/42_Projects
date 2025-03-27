/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 09:52:56 by pfalli            #+#    #+#             */
/*   Updated: 2024/04/10 09:57:12 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//	void	print_stack(t_stack_node *a)
//	{
//		t_stack_node	*curr;
//	
//		curr = a;
//		while (curr)
//		{
//			printf("%d ->", curr->data);
//			curr = curr->next;
//		}
//		printf("\n");
//	}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = split(argv[1], ' ');
	init_stack_node_a(&a, argv + 1);
	
	//	print_stack(a);
	//	exit(0);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);
	return (0);
}
