/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazem <mrazem@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:16:17 by mrazem            #+#    #+#             */
/*   Updated: 2025/06/02 17:35:13 by mrazem           ###   ########.fr       */
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
/* 
int	find_min_index(data)
{
	t_node *curr;

}

void	sort_five(t_data *data)
{
	if head > head+1

	sort_3(data);
}


void	radix_sort(t_data *data)
{
	int i = 0;
	int j;
	int size = data->a->len;
	int max_bits = 0;

	if (size <= 3)
		return (sort_three(data));
	if (size <= 5)
		return (sort_five(data));

	while ((size - 1) >> max_bits)
		max_bits++;

	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((data->a->head->index >> i) & 1) == 0)
				pb(data);
			else
				ra(data);
			j++;
		}
		while (data->b->len)
			pa(data);
		i++;
	}
}
 */