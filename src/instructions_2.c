/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazem <mrazem@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 00:32:31 by mrazem            #+#    #+#             */
/*   Updated: 2025/06/04 02:13:34 by mrazem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//REVERSE ROTATE A
void	rra(t_data *data)
{
	reverse_rotate_stack(data->a);
	append_instructions(data, "rra");
}

//ROTATE A
void	ra(t_data *data)
{
	rotate_stack(data->a);
	append_instructions(data, "ra");
}
