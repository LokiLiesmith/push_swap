/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazem <mrazem@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 21:55:41 by mrazem            #+#    #+#             */
/*   Updated: 2025/06/04 02:56:41 by mrazem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//APPEND INSTRUCTIONS TO LIST
void	append_instructions(t_data *data, char *operation)
{
	t_op	*new_op;

	new_op = malloc(sizeof(t_op));
	if (!new_op)
		return ;
	new_op->operation = ft_strdup(operation);
	new_op->prev = data->op_list->tail;
	new_op->next = NULL;
	if (data->op_list->tail)
		data->op_list->tail->next = new_op;
	else
		data->op_list->head = new_op;
	data->op_list->tail = new_op;
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
		ft_printf("%d\n", current->index);
		current = current->next;
	}
	ft_printf("\n");
}

int	number_of_instructions(t_data *data)
{
	int		count;
	t_op	*op;

	count = 0;
	op = data->op_list->head;
	while (op)
	{
		count++;
		op = op->next;
	}
	return (count);
}
