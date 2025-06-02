/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazem <mrazem@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 21:37:11 by mrazem            #+#    #+#             */
/*   Updated: 2025/06/02 02:02:31 by mrazem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../include/libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_node
{
	long			value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	int		len;
	t_node	*head;
	t_node	*tail;
}	t_stack;

typedef struct s_op
{
	struct s_op	*next;
	struct s_op	*prev;
	char		*operation;
}	t_op;

typedef struct s_op_list
{
	t_op	*head;
	t_op	*tail;
}	t_op_list;

typedef struct s_data
{
	t_stack			*a;
	t_stack			*b;
	t_op_list		*op_list;
}	t_data;

//STACK_INIT.C
t_stack	*init_stacks(t_data *data, int arr[], int arr_len);
void	create_node(t_stack *stack, int value);
void	assign_indexes(t_stack *stack);

//STACK_UTILS.C
void	create_node(t_stack *stack, int value);
void	push_node_to_stack(t_stack *stack, t_node *node);
t_node	*pop_head(t_stack *stack);
t_node	*pop_tail(t_stack *stack);
void	append_tail(t_stack *stack, t_node *node);
void	append_node(t_stack *stack, int input);
void	print_stack(t_stack *stack);

//TROUBLESHOOTING
void	print_index(t_stack *stack);

//OPERATIONS.C
void	swap_top(t_stack *stack);
void	rotate_stack(t_stack *stack);
void	reverse_rotate_stack(t_stack *stack);

void	pa(t_data *data);
void	pb(t_data *data);
void	append_instructions(t_data *data, char *operation);



#endif
