/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazem <mrazem@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 02:23:01 by mrazem            #+#    #+#             */
/*   Updated: 2025/06/02 15:42:54 by mrazem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->a = malloc(sizeof(t_stack));
	data->b = malloc(sizeof(t_stack));
	data->op_list = malloc(sizeof(t_op_list));
	if (!data->a || !data->b || !data->op_list)
	{
		if (data->a)
			free(data->a);
		if (data->b)
			free(data->b);
		if (data->op_list)
			free(data->op_list);
		free(data);
		return (NULL);
	}
	return (data);
}

void	fill_data(t_data *data, int arr[], int arr_len)
{
	int	i;

	i = 0;
	data->a->head = NULL;
	data->a->tail = NULL;
	data->b->head = NULL;
	data->b->tail = NULL;
	data->op_list->head = NULL;
	data->op_list->tail = NULL;

	while (i <= arr_len - 1)
	{
		create_node(data->a, arr[i]);
		i++;
	}
	assign_indexes(data->a);
}

// t_stack	*init_stacks(t_data *data, int arr[], int arr_len)
// {
// 	int		i;

// 	i = 0;
// 	data->a = malloc(sizeof(t_stack));
// 	if (!data->a)
// 		return (NULL);
// 	data->a->head = NULL;
// 	data->a->tail = NULL;
// 	data->b = malloc(sizeof(t_stack));
// 	if (!data->b)
// 	{
// 		free(data->a);
// 		return (NULL);
// 	}
// 	data->b->head = NULL;
// 	data->b->tail = NULL;
// 	while (i <= arr_len - 1)
// 	{
// 		create_node(data->a, arr[i]);
// 		i++;
// 	}
// 	assign_indexes(data->a);

// 	return (data->a);
// }

//PREPEND NODE TO STACK
void	create_node(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = stack->head;
	new_node->prev = NULL;
	if (stack->head == NULL)
	{
		stack->head = new_node;
		stack->tail = new_node;
	}
	else
	{
		stack->head->prev = new_node;
		stack->head = new_node;
	}
	stack->len++;
}

void	assign_indexes(t_stack *stack)
{
	t_node	*current;
	t_node	*compare;
	int		index;

	current = stack->head;
	while (current)
	{
		index = 0;
		compare = stack->head;
		while (compare)
		{
			if (compare->value < current->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

void	print_index(t_stack *stack)
{
	t_node	*current;

	current = stack->head;
	while (current)
	{
		printf("%d ", current->index);
		current = current->next;
	}
	printf("\n");
}
