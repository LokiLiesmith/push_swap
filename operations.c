//     sa(t_data *d)

//     pb(t_data *d)

//     rr(t_data *d)

//SWAP HEAD AND 2ND
void	swap_top(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || stack->len < 2)
		return ;

	first = stack->head;
	second = first->next;

	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	second->prev - NULL;
	first->prev = second;
	stack->head = second;
	if (stack->len == 2)
		stack->tail = first;
}
