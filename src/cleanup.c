/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazem <mrazem@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 01:07:05 by mrazem            #+#    #+#             */
/*   Updated: 2025/06/04 22:51:52 by mrazem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stacks(t_data *data)
{
	t_node	*tmp;

	if (!data)
		return ;
	if (data->a)
	{
		while (data->a && data->a->head)
		{
			tmp = data->a->head->next;
			free(data->a->head);
			data->a->head = tmp;
		}
		free(data->a);
	}
	if (data->b)
	{
		while (data->b && data->b->head)
		{
			tmp = data->b->head->next;
			free(data->b->head);
			data->b->head = tmp;
		}
		free(data->b);
	}
}

void	free_list(t_data *data)
{
	t_op	*op_tmp;

	if (!data || !data->op_list)
		return ;
	while (data->op_list && data->op_list->head)
	{
		op_tmp = data->op_list->head->next;
		free(data->op_list->head->operation);
		free(data->op_list->head);
		data->op_list->head = op_tmp;
	}
	free(data->op_list);
}

void	free_vars(t_data *data)
{
	if (!data)
		return ;
	if (data->vars)
		free(data->vars);
}

void	free_data(t_data *data)
{
	free_stacks(data);
	free_list(data);
	free_vars(data);
	free(data);
}
