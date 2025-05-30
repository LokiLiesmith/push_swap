/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazem <mrazem@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 21:40:04 by mrazem            #+#    #+#             */
/*   Updated: 2025/05/30 21:21:08 by mrazem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prepend_node(t_stack *stack, int input)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = input;
	new_node->next = stack->head;
	new_node->prev = NULL;
	if (stack->head == NULL)
	{
		stack->head = new_node;
		stack->tail = new_node;
	}
	else
	{
		stack->head->prev = new_node;
		stack->head = new_node;
	}
	stack->len++;
}
void	append_node(t_stack *stack, int input)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = input;
	new_node->next = NULL;
	new_node->prev = stack->tail;
	if (stack->head == NULL)
	{
		stack->head = new_node;
		stack->tail = new_node;
	}
	else
	{
		stack->tail->next = new_node;
		stack->tail = new_node;
	}
	stack->len++;
}

t_stack	*init_stacks(t_data *data, int arr[], int arr_len)
{
	int		i;
	
	i = 0;
	data->a = malloc(sizeof(t_stack));
	data->a->head = NULL;
	data->a->tail = NULL;
	data->b = malloc(sizeof(t_stack));//IFITFAILS YADAYADA
	data->b->head = NULL;
	data->b->tail = NULL;
	while (i <= arr_len - 1)
	{
		append_node(data->a, arr[i]);
		i++;
	}
	return (data->a);
}

int	main(void)
{
	t_data data;
	t_node *loop;

	int	input[7] = {4, 3, 1, 5, 2, 20, 11};
	int	arr_len = 7;
	
	init_stacks(&data, input, arr_len);

	loop = data.a->head;
	while(loop)
	{
		printf("%ld ", loop->value);
		loop = loop->next;
	}


	// printf("%p\n", data);
	
	
	return (0);
}


// int	main(int argc, char *argv[])
// {
// 	if arg

// 	return (0);
// }