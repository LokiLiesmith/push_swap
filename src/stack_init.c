/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazem <mrazem@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 02:23:01 by mrazem            #+#    #+#             */
/*   Updated: 2025/05/31 23:53:10 by mrazem           ###   ########.fr       */
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
