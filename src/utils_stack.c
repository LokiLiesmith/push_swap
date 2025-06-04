/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazem <mrazem@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 00:30:27 by mrazem            #+#    #+#             */
/*   Updated: 2025/06/04 18:36:58 by mrazem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// PUSH NODE TO STACK (stack, node)
void	push_node_to_stack(t_stack *stack, t_node *node)
{
	node->next = stack->head;
	node->prev = NULL;
	if (stack->head)
		stack->head->prev = node;
	else
		stack->tail = node;
	stack->head = node;
	stack->len++;
}

// POP NODE FROM HEAD (stack)
t_node	*pop_head(t_stack *stack)
{
	t_node	*node;

	node = stack->head;
	stack->head = node->next;
	if (stack->head)
		stack->head->prev = NULL;
	else
		stack->tail = NULL;
	node->next = NULL;
	node->prev = NULL;
	stack->len--;
	return (node);
}

// POP NODE FROM TAIL (stack)
t_node	*pop_tail(t_stack *stack)
{
	t_node	*node;

	node = stack->tail;
	stack->tail = node->prev;
	if (stack->tail)
		stack->tail->next = NULL;
	else
		stack->head = NULL;
	node->next = NULL;
	node->prev = NULL;
	stack->len--;
	return (node);
}

// APPEND NODE TO TAIL (stack, node)
void	append_tail(t_stack *stack, t_node *node)
{
	node->next = NULL;
	node->prev = stack->tail;
	if (stack->tail == NULL)
	{
		stack->tail = node;
		stack->head = node;
	}
	else
	{
		stack->tail->next = node;
		node->prev = stack->tail;
		stack->tail = node;
	}
	stack->len++;
}

//	PRINT STACK (stack)
void	print_stack(t_stack *stack)
{
	t_node	*current;

	current = stack->head;
	while (current)
	{
		ft_printf("%d ", current->value);
		current = current->next;
	}
	ft_printf("\n");
}
