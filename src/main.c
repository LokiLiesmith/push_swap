/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazem <mrazem@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 21:40:04 by mrazem            #+#    #+#             */
/*   Updated: 2025/05/30 01:08:24 by mrazem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_stack	*init_stacks(int arr[], int arr_len)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	i = 0;
	a = malloc(sizeof(t_stack));//IFITFAILS YADAYADA
	a->head = NULL;
	a->tail = NULL;
	b = malloc(sizeof(t_stack));//IFITFAILS YADAYADA
	b->head = NULL;
	b->tail = NULL;
	while (i <= arr_len - 1)
	{
		append_node(a, arr[i]);
		i++;
	}
	return (a);
}

int	main(void)
{
	t_stack	*a;
	t_node	*current;
	int	input[7] = {4, 3, 1, 5, 2, 20, 11};
	int	arr_len = 7;

	a = init_stacks(input, arr_len);
	current = a->head;
	printf("Stack A: ");
	while (current)
	{
		printf("%ld ", current->value);
		current = current->next;
	}
	printf("\n");
	return (0);
}
// int	main(int argc, char *argv[])
// {
// 	if arg

// 	return (0);
// }