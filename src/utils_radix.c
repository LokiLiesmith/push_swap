/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_radix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazem <mrazem@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 02:44:56 by mrazem            #+#    #+#             */
/*   Updated: 2025/06/04 02:50:39 by mrazem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_radix_vars(t_data *data)
{
	data->vars->i = 0;
	data->vars->j = 0;
	data->vars->size = data->a->len;
	data->vars->max_bits = 0;
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->head)
		return (1);
	current = stack->head;
	while (current->next)
	{
		if (current->index > current->next->index)
			return (0);
		current = current->next;
	}
	return (1);
}

int	find_min_index(t_data *data)
{
	int		min;
	t_node	*current;

	current = data->a->head;
	min = current->index;
	while (current)
	{
		if (current->index < min)
			min = current->index;
		current = current->next;
	}
	return (min);
}
