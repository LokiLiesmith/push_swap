/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazem <mrazem@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 21:37:11 by mrazem            #+#    #+#             */
/*   Updated: 2025/06/04 02:49:28 by mrazem           ###   ########.fr       */
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

typedef struct s_vars
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

}	t_vars;

typedef struct s_data
{
	t_vars			*vars;
	t_stack			*a;
	t_stack			*b;
	t_op_list		*op_list;
}	t_data;

//DATA_INIT.C
t_data	*init_data(void);
void	fill_data(t_data *data, int arr[], int arr_len);
void	create_node(t_stack *stack, int value);

//INSTRUCTIONS.C
void	sa(t_data *data);
void	sb(t_data *data);
void	pa(t_data *data);
void	pb(t_data *data);

//INSTRUCTIONS_2.C
void	rra(t_data *data);
void	ra(t_data *data);

//RADIX_SORT.C
void	sort_three(t_data *data);
void	sort_five(t_data *data);
void	radix_sort(t_data *data);

//UTILS_RADIX.C
void	init_radix_vars(t_data *data);
int		is_sorted(t_stack *stack);
int		find_min_index(t_data *data);

//INPUT_PARSER.C
char	*join_input(int argc, char **argv);
int		*convert_to_int_arr(char **input, int len);
int		check_duplicates(int *arr, int len);
int		count_tokens(char **input);
int		*check_input(int argc, char **argv, int *arr_len);

// UTILS_PARSER.C
long	ft_atol(const char *s);
void	ft_free_split(char **arr);
int		is_valid_int_string(char *s);
int		is_in_int_range(char *s);
int		is_valid_int(char *s);

//UTILS_LIST.C
void	append_instructions(t_data *data, char *operation);
void	assign_indexes(t_stack *stack);
void	print_index(t_stack *stack);
int		number_of_instructions(t_data *data);

//UTILS_STACK.C
void	push_node_to_stack(t_stack *stack, t_node *node);
t_node	*pop_head(t_stack *stack);
t_node	*pop_tail(t_stack *stack);
void	append_tail(t_stack *stack, t_node *node);
void	print_stack(t_stack *stack);

//UTILS_STACK_2.C
int		swap_top(t_stack *stack);
void	rotate_stack(t_stack *stack);
void	reverse_rotate_stack(t_stack *stack);

//CLEANUP.C
void	free_stacks(t_data *data);
void	free_list(t_data *data);
void	free_vars(t_data *data);
void	free_data(t_data *data);

#endif
