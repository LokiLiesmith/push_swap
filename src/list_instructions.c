/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazem <mrazem@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 21:55:41 by mrazem            #+#    #+#             */
/*   Updated: 2025/06/01 22:12:37 by mrazem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	append_instructions(t_data *data, char *operation)
{
	t_op	*new_op;

	new_op = malloc(sizeof(t_instr));
	if (!new_op)
		return ;

	new_op->operation = operation;
	new_op->prev = data->op_list->tail;
	new_op->next = NULL;

	if (data->op_list->tail)
		data->op_list->tail->next = new_op;
	else
		data->op_list->head = new_op;
	data->op_list->tail = new_op;
}
