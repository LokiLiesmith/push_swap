/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrazem <mrazem@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:51:36 by mrazem            #+#    #+#             */
/*   Updated: 2025/05/29 21:38:13 by mrazem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct s_node
{
	int				x;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_list
{
	int		len;
	s_node	*head;
	s_node	*tail;
}	t_list;

t_list *append_to_list()


int main(void)
{
	t_node	root_a;




	return (0);
}






// int main(void)
// {
// 	t_node root;
// 	t_node r1;

// 	int a = 0;
// 	root.x = 0;

// 	t_node *new = &root;
// 	{
// 		while (new != NULL)
// 			printf("%d\\n", new->x);
// 			new = new->next;
// 			a++;
// 	}
// }
