/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazem <mrazem@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 21:40:04 by mrazem            #+#    #+#             */
/*   Updated: 2025/06/04 18:39:38 by mrazem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_op_list *list)
{
	t_op	*current;

	current = list->head;
	while (current)
	{
		ft_printf("%s\n", current->operation);
		current = current->next;
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;
	int		*validated;
	int		arr_len;

	validated = check_input(argc, argv, &arr_len);
	if (!validated)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	data = init_data();
	if (!data)
		return (1);
	fill_data(data, validated, arr_len);
	free(validated);
	if (!is_sorted(data->a))
		radix_sort(data);
	print_list(data->op_list);
	free_data(data);
	return (0);
}
//////////////////////// TO-DO ///////////////////////////
// input handling
// run the checker
// cleanup after done
// optimizing the algo optional
//printfs - change to ft_printf
// argv[]      →  char **
//             →  ft_split → array of strings ("3", "2", "1", ...)
//             →  string to int with validation
//             →  store into stack a using create_node(stack, int)
//////////////////////////////////////////////////////////
/* int	main(int argc, char **argv)
{
	t_data	*data;
	int		*validated;
	int		arr_len;
	validated = check_input(argc, argv, &arr_len);
	if (!validated)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	data = init_data();
	if (!data)
		return (1);
	fill_data(data, validated, arr_len);
	free(validated);
/////////////////////// TESTING ////////////////////////////////
// radix_sort(data);
	// print_stack(data->a);
	// print_stack(data->b);
	if (!is_sorted(data->a))
		radix_sort(data);
	// sort_three(data);
	// // sort_five(data);
	// print_stack(data->a);
	// print_stack(data->b);
	
	print_list(data->op_list);
	// printf("\nTOTAL: %d\n", number_of_instructions(data));
	// print_index(data->a);
	free_data(data);

	return (0);
} */