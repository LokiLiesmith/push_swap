/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazem <mrazem@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 23:45:09 by mrazem            #+#    #+#             */
/*   Updated: 2025/06/04 02:12:37 by mrazem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//SWAP A
void	sa(t_data *data)
{
	if (swap_top(data->a))
		append_instructions(data, "sa");
}

//SWAP B
void	sb(t_data *data)
{
	if (swap_top(data->b))
		append_instructions(data, "sb");
}

//PUSH A
void	pa(t_data *data)
{
	t_node	*node;

	if (data->b->head == NULL)
		return ;
	node = pop_head(data->b);
	push_node_to_stack(data->a, node);
	append_instructions(data, "pa");
}

//PUSH B
void	pb(t_data *data)
{
	t_node	*node;

	if (data->a->head == NULL)
		return ;
	node = pop_head(data->a);
	push_node_to_stack(data->b, node);
	append_instructions(data, "pb");
}
