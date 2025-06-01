/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazem <mrazem@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 23:45:09 by mrazem            #+#    #+#             */
/*   Updated: 2025/06/01 22:37:01 by mrazem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//     sa(t_data *d)
void	s_a(t_data *data)
{
	swap_top(data->a);
	// store to node - append node to instr list.
	// swap
	// store instr
}

//PUSH A
void	pa(t_data *data)
{
	push_node_to_stack(data->b, pop_head(data->a));
	printf("PA\n");
	// append_instructions(data, "PA");
}

//PUSH B
void	pb(t_data *data)
{
	push_node_to_stack(data->a, pop_head(data->b));
	printf("PB\n");
}
//     pb(t_data *d)

//     rr(t_data *d)
