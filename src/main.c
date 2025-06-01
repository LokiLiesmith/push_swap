/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazem <mrazem@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 21:40:04 by mrazem            #+#    #+#             */
/*   Updated: 2025/06/01 22:25:20 by mrazem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_op_list *list)
{
	t_op	*current;

	current = list->head;
	while (current)
	{
		printf("%s ", current->operation);
		current = current->next;
	}
	printf("\n");
}


int	main(void)
{
	t_data	data;
	int		input_arr[] = {0, 36, 40, 25, 2, 34, 38, 6, 31, 50, 44, 20, 27, 46, 23, 3, 39, 13, 37, 49, 35, 45, 10, 18, 21, 4, 12, 14, 16, 28, 24, 1, 33, 9, 17};
	int		arr_len = 35;

	init_stacks(&data, input_arr, arr_len);
	print_stack(data.a);
	print_stack(data.b);
	// print_index(data.a);

	pa(&data);
	pa(&data);
	pa(&data);
	print_stack(data.a);
	print_stack(data.b);
	pb(&data);
	print_stack(data.a);
	print_stack(data.b);
	// print_index(data.a);

	return (0);
}
