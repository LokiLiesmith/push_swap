/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazem <mrazem@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 23:45:09 by mrazem            #+#    #+#             */
/*   Updated: 2025/06/02 17:51:49 by mrazem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//SWAP A
void	sa(t_data *data)
{
	if (swap_top(data->a))
		append_instructions(data, "sa");
}

//PUSH A
void	pa(t_data *data)
{
	t_node	*node;
	
	if (data->a->head == NULL)
		return ;
	node = pop_head(data->a);
	push_node_to_stack(data->b, node);
	append_instructions(data, "pa");
}

//PUSH B
void	pb(t_data *data)
{
	t_node	*node;
	
	if (data->a->head == NULL)
		return ;
	node = pop_head(data->a);
	push_node_to_stack(data->a, pop_head(data->b));
	append_instructions(data, "pb");
}

//ROTATE A
void	ra(t_data *data)
{
	rotate_stack(data->a);
	append_instructions(data, "ra");
}

//REVERSE ROTATE A
void	rra(t_data *data)
{
	reverse_rotate_stack(data->a);
	append_instructions(data, "rra");
}
