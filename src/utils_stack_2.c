/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazem <mrazem@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 22:47:50 by mrazem            #+#    #+#             */
/*   Updated: 2025/06/04 18:37:12 by mrazem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//SWAP HEAD AND 2ND
int	swap_top(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || stack->len < 2)
		return (0);
	first = stack->head;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	stack->head = second;
	if (first->next == NULL)
		stack->tail = first;
	return (1);
}

//ROTATE: HEAD >> TAIL
void	rotate_stack(t_stack *stack)
{
	t_node	*node;

	node = pop_head(stack);
	append_tail(stack, node);
}

//REVERSE-ROTATE TAIL >> HEAD
void	reverse_rotate_stack(t_stack *stack)
{
	t_node	*node;

	node = pop_tail(stack);
	push_node_to_stack(stack, node);
}
