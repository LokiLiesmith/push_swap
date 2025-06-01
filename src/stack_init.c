/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazem <mrazem@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 02:23:01 by mrazem            #+#    #+#             */
/*   Updated: 2025/06/01 20:29:58 by mrazem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stacks(t_data *data, int arr[], int arr_len)
{
	int		i;

	i = 0;
	data->a = malloc(sizeof(t_stack));
	if (!data->a)
		return (NULL);
	data->a->head = NULL;
	data->a->tail = NULL;
	data->b = malloc(sizeof(t_stack));
	if (!data->b)
	{
		free(data->a);
		return (NULL);
	}
	data->b->head = NULL;
	data->b->tail = NULL;
	while (i <= arr_len - 1)
	{
		create_node(data->a, arr[i]);
		i++;
	}
	assign_indexes(data->a);

	return (data->a);
}

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
