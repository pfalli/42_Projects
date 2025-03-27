/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 09:52:52 by pfalli            #+#    #+#             */
/*   Updated: 2024/04/10 09:57:58 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"

// double linked list
typedef struct s_stack_node
{
    int data;
    int on_top_cost; // number of commands
    int index; // number of rotation to do to bring the number on top of the stack, before to push
    bool above_median; 
    bool cheapest;
    struct s_stack_node *target_node;
    struct s_stack_node *next;
    struct s_stack_node *prev;
}               t_stack_node;

// Utils
char **split(char *s, char c);

// Handle errors

int	            error_syntax(char *argv);
int	            error_duplicate(t_stack_node *a, int n);
void	        free_stack(t_stack_node **stack);
void	        free_errors(t_stack_node **a);

// Stack initialization
void	        init_stack_node_a(t_stack_node **a, char **argv);

// Nodes initialization
void	        set_index(t_stack_node *stack);
void	        set_cheapest(t_stack_node *stack);
void	        info_nodes_a(t_stack_node *a, t_stack_node *b);
void	info_nodes_b(t_stack_node *a, t_stack_node *b);

// Stack utils
t_stack_node	*find_last(t_stack_node *stack);
int	            stack_len(t_stack_node *stack);
bool	        stack_sorted(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
t_stack_node	*get_cheapest_node(t_stack_node *stack);
void	put_to_top(t_stack_node **stack, t_stack_node *top_node, char stack_name);

// Commands
void            ra(t_stack_node **a, bool print);
void            rb(t_stack_node **b, bool print);
void            rr(t_stack_node **a, t_stack_node **b, bool print);
void            rra(t_stack_node **a, bool print);
void            rrb(t_stack_node **b, bool print);
void            rrr(t_stack_node **a, t_stack_node **b, bool print);
void            pa(t_stack_node **a, t_stack_node **b , bool print);
void            pb(t_stack_node **a, t_stack_node **b, bool print);
void        	sa(t_stack_node	**a, bool print);
void        	sb(t_stack_node **b, bool print);
void        	ss(t_stack_node **a, t_stack_node **b, bool print);
// Algorithm
void	        sort_three(t_stack_node **a);
void	        sort_stacks(t_stack_node **a, t_stack_node **b);



//  DELETE LATER
//  void	print_stack(t_stack_node *a);
#endif