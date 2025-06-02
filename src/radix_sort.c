/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazem <mrazem@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:16:17 by mrazem            #+#    #+#             */
/*   Updated: 2025/06/02 22:55:51 by mrazem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_data *data)
{
	int	a;	
	int	b;	
	int	c;

	a = data->a->head->index;
	b = data->a->head->next->index;
	c = data->a->tail->index;
	if (a > b && b < c && a < c)
		sa(data);
	else if (a < b && b > c && a < c)
	{
		rra(data);
		sa(data);
	}
	else if (a < b && b > c && a > c)
		rra(data);
	else if (a > b && b < c && a > c)
		ra(data);
	else if (a > b && b > c && a > c)
	{
		sa(data);
		rra(data);
	}
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

void	sort_five(t_data *data)
{
	while (data->a->len > 3)
	{
		if (data->a->head->index == find_min_index(data))
			pb(data);
		else
			ra(data);
	}
	sort_three(data);
	if (data->b->len > 1 && data->b->head->index < data->b->tail->index)
		sb(data);
	pa(data);
	pa(data);
}

void	init_radix_vars(t_data *data)
{
	data->vars->i = 0;
	data->vars->j = 0;
	data->vars->size = data->a->len;
	data->vars->max_bits = 0;
}

void	radix_sort(t_data *data)
{
	init_radix_vars(data);
	if (data->vars->size <= 3)
		return (sort_three(data));
	if (data->vars->size <= 5)
		return (sort_five(data));
	while ((data->vars->size - 1) >> data->vars->max_bits)
		data->vars->max_bits++;
	while (data->vars->i < data->vars->max_bits)
	{
		data->vars->j = 0;
		while (data->vars->j < data->vars->size)
		{
			if (((data->a->head->index >> data->vars->i) & 1) == 0)
				pb(data);
			else
				ra(data);
			data->vars->j++;
		}
		while (data->b->len)
			pa(data);
		data->vars->i++;
	}
}
