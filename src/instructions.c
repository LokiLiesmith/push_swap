/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazem <mrazem@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 23:45:09 by mrazem            #+#    #+#             */
/*   Updated: 2025/06/02 15:52:28 by mrazem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//SWAP A
void	s_a(t_data *data)
{
	swap_top(data->a);
	append_instructions(data, ft_strdup("sa"));
}

//PUSH A
void	pa(t_data *data)
{
	push_node_to_stack(data->b, pop_head(data->a));
	printf("PA\n");
	append_instructions(data, ft_strdup("pa"));
}

//PUSH B
void	pb(t_data *data)
{
	push_node_to_stack(data->a, pop_head(data->b));
	append_instructions(data, ft_strdup("pb"));
}

//ROTATE A
void	ra(t_data *data)
{
	rotate_stack(data->a);
	append_instructions(data, ft_strdup("ra"));
}
