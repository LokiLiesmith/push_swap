/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazem <mrazem@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 00:30:27 by mrazem            #+#    #+#             */
/*   Updated: 2025/05/31 02:35:02 by mrazem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//         push_node_to_stack()
void	push_node_to_stack(t_stack *stack, t_node *node)
{
	node->next = stack->head;
	node->prev = NULL;
	if (stack->head)
		stack->head->prev = node;
	else
		stack->tail = node;
	stack->len++;
}

// POP NODE FROM HEAD
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

// POP NODE FROM TAIL
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

void	append_tail(t_stack *stack, t_node *node)
{
	t_node	*new_node;

	node->next = NULL;
	node->prev = stack->tail;
	if (stack->tail == NULL)
	{
		stack->tail = node;
		stack->head = node;
	}
	else
	{
		stack->tail->prev = node;
		stack->tail = node;
	}
	stack->len++;
}

//ROTATE: HEAD >> TAIL
void	rotate_stack(t_stack *stack)
{
	t_node	*node;

	node = pop_head(stack);
	append_tail(node);
}
/* 
void	rotate_stack(t_stack *stack)
{
	t_node	*node;

	if (!stack || stack->len < 2)
		return ;

	node = pop_from_stack(stack); // Removes head and returns it
	node->next = NULL;
	node->prev = stack->tail;

	if (stack->tail)
		stack->tail->next = node;

	stack->tail = node;

	if (!stack->head) // If stack was only 1 node, set head
		stack->head = node;
}
 */

//         reverse_rotate()