#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*last;
}	t_node;

t_node	*create_node(int value)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	new->last = NULL;
	return(new);
}

int	main(void)
{
	t_node	*n1;
	t_node	*n2;
	t_node	*n3;

	n1 = create_node(1);
	n2 = create_node(2);
	n3 = create_node(3);

	

	printf("n1 value: %d\n", n1->value);
	printf("n1 adress: %p\n", (void *)n1);
	printf("n1 adress: %p\n", &n1);
	printf("n1 next: %p\n", n1->next);
	printf("n1 last: %p\n", n1->last);
	printf("n2 value: %d\n", n2->value);
	printf("n2 adress: %p\n", &n2);
	printf("n2 next: %p\n", n2->next);
	printf("n2 last: %p\n", n2->last);
	printf("n3 value: %d\n", n3->value);
	printf("n3 adress: %p\n", &n3);
	printf("n3 next: %p\n", n3->next);
	printf("n3 last: %p\n", n3->last);

	// t_node	n1;
	// t_node	n2;

	// n1.value = 3;
	// n2.value = 4;
	// n1.next = &n2;
	// n1.last = NULL;

	// n2.last = &n1;
	// n2.next = NULL;

	// printf("n1.value= %d\n", n1.value);
	// printf("n1.adress= %p\n", &n1);
	// printf("n2.adress= %p\n", &n2);
	// printf("n1.next= %p\n", n1.next);
	// printf("n1.last= %p\n", n1.last);
	// printf("n2.next= %p\n", n2.next);
	// printf("n2.last= %p\n", n2.last);
	// printf("n2.value= %d\n", n2.value);
	return (0);
}
