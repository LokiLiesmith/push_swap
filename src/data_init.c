/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazem <mrazem@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 02:23:01 by mrazem            #+#    #+#             */
/*   Updated: 2025/06/04 22:52:18 by mrazem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ALLOCATE STRUCT SPACE
t_data	*init_data(void)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->a = malloc(sizeof(t_stack));
	data->b = malloc(sizeof(t_stack));
	data->op_list = malloc(sizeof(t_op_list));
	data->vars = malloc(sizeof(t_vars));
	if (!data->a || !data->b || !data->op_list ||!data->vars)
	{
		if (data->a)
			free(data->a);
		if (data->b)
			free(data->b);
		if (data->op_list)
			free(data->op_list);
		if (data->vars)
			free(data->vars);
		free(data);
		return (NULL);
	}
	return (data);
}

//FILL STACK A WITH VALIDATED INPUT
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
	data->a->len = 0;
	data->b->len = 0;
	data->vars->i = 0;
	data->vars->j = 0;
	data->vars->max_bits = 0;
	data->vars->size = 0;
	while (i <= arr_len - 1)
	{
		create_node(data->a, arr[i]);
		i++;
	}
	assign_indexes(data->a);
}

//APPEND NODE TO STACK
void	create_node(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = stack->tail;
	if (stack->tail == NULL)
	{
		stack->head = new_node;
		stack->tail = new_node;
	}
	else
	{
		stack->tail->next = new_node;
		stack->tail = new_node;
	}
	stack->len++;
}
