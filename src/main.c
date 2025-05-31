/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazem <mrazem@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 21:40:04 by mrazem            #+#    #+#             */
/*   Updated: 2025/06/01 01:08:31 by mrazem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	t_data	data;
	int		input_arr[7] = {4, 3, 1, 5, 2, 20, 11};
	int		arr_len = 7;

	init_stacks(&data, input_arr, arr_len);
	print_stack(data.a);
	print_stack(data.b);
	create_node(data.a, 45);
	create_node(data.b, 777);
	print_stack(data.a);
	print_stack(data.b);
	swap_top(data.a);
	print_stack(data.a);
	rotate_stack(data.a);
	print_stack(data.a);
	reverse_rotate_stack(data.a);
	reverse_rotate_stack(data.a);
	reverse_rotate_stack(data.a);
	print_stack(data.a);
	return (0);
}
