/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazem <mrazem@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:16:17 by mrazem            #+#    #+#             */
/*   Updated: 2025/06/04 22:52:40 by mrazem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_data *data)
{
	int	a;	
	int	b;	
	int	c;

	if (data->a->len == 2 && data->a->head->index > data->a->head->next->index)
	sa(data);
	else
	{
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
}

void	sort_five(t_data *data)
{
	int	min_pos;

	while (data->a->len > 3)
	{
		min_pos = find_min_pos(data->a);
		if (min_pos == 0)
			pb(data);
		else if (min_pos <= data->a->len / 2)
			ra(data);
		else
			rra(data);
	}
	sort_three(data);
	if (data->b->len > 1 && data->b->head->index < data->b->tail->index)
		sb(data);
	pa(data);
	pa(data);
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
