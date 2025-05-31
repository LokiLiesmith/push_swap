/* void	optimize_instructions(t_data *data)
{
	t_inst *cur = data->instr_head;

	while (cur && cur->next)
	{
		if (
			(!ft_strcmp(cur->op, "ra") && !ft_strcmp(cur->next->op, "rra")) ||
			(!ft_strcmp(cur->op, "rra") && !ft_strcmp(cur->next->op, "ra")) ||
			(!ft_strcmp(cur->op, "sa") && !ft_strcmp(cur->next->op, "sa"))
			)
		{
			// 🗑 remove both
			t_inst *to_delete1 = cur;
			t_inst *to_delete2 = cur->next;

			// link over the pair
			if (to_delete1->prev)
				to_delete1->prev->next = to_delete2->next;
			else
				data->instr_head = to_delete2->next;

			if (to_delete2->next)
				to_delete2->next->prev = to_delete1->prev;
			else
				data->instr_tail = to_delete1->prev;

			cur = to_delete1->prev ? to_delete1->prev : data->instr_head;

			free(to_delete1->op);
			free(to_delete1);
			free(to_delete2->op);
			free(to_delete2);
		}
		else
			cur = cur->next;
	}
}
 */

/* 
 /// ALSO ADD 

 🧪 Bonus Challenge:

Try detecting:

    "pb", "pa" → cancel

    "ra", "rb" → replace with "rr"

    "rra", "rrb" → "rrr" */