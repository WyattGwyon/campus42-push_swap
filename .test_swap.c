/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouden <clouden@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 18:56:10 by clouden           #+#    #+#             */
/*   Updated: 2025/08/08 18:56:12 by clouden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_stack_node
{
	int					value;
	//int					index;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}	t_stack_node;

void	swap(t_stack_node **head)
{
	if ((*head)->next == (*head)->prev)
	{
		*head = (*head)->next;
		return ;
	}
	(*head)->prev->next = (*head)->next;
	(*head)->next->next->prev = *head;
	(*head)->next->prev = (*head)->prev;
	(*head)->prev = (*head)->next;
	(*head)->next = (*head)->next->next;
	(*head)->prev->next = *head;
	*head = (*head)->prev;
}

void	sa(t_stack_node **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack_node **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
// ==============================================================

// ==============================================================
void	rev_rotate(t_stack_node **head)
{
	*head = (*head)->prev;
}

void	rra(t_stack_node **a)
{
	rev_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b)
{
	rev_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	rev_rotate(a);
	rev_rotate(b);
	write(1, "rrr\n", 4);
}
// ==============================================================

// ==============================================================
void	rotate(t_stack_node **head)
{
	*head = (*head)->next;
}

void	ra(t_stack_node **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack_node **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
// ==============================================================

// ==============================================================
void	push(t_stack_node **dest_head, t_stack_node **src_head)
{
	t_stack_node	*push_node;

	push_node = *src_head;
	if (push_node->next == push_node)
		*src_head = NULL;
	else
	{
		(*src_head)->next->prev = (*src_head)->prev;
		(*src_head)->prev->next = (*src_head)->next;
		*src_head = (*src_head)->next;
	}
	if (!dest_head || !*dest_head)
	{
		push_node->next = push_node;
		push_node->prev = push_node;
		*dest_head = push_node;
	}
	else
	{
		push_node->prev = (*dest_head)->prev;
		push_node->next = *dest_head;
		push_node->prev->next = push_node;
		push_node->next->prev = push_node;
		*dest_head = push_node;
	}
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	if (!b || !*b)
		return ;
	push(a,b);
	write(1, "pa\n", 3);
}

void	pb(t_stack_node **a, t_stack_node **b)
{
	if (!a || !*a)
		return ;
	push(b,a);
	write(1,"pb\n", 3);
}
// ==============================================================

// ==============================================================
void print_stack(t_stack_node *stack, char name)
{
	if (!stack)
	{
		printf("stack %c is empty\n", name);
		return;
	}
	t_stack_node *start = stack;
	printf("stack %c: ", name);
	do
	{
		printf("%d ", stack->value);
		stack = stack->next;
	} while (stack && stack != start);
	printf("\n");
}

t_stack_node *create_node(int value)
{
	t_stack_node *node = malloc(sizeof(t_stack_node));
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return node;
}
t_stack_node *create_short()
{
	t_stack_node *n1 = create_node(1);
	t_stack_node *n2 = create_node(2);
	
	n1->next = n2;
	n2->next = n1;
	

	n1->prev = n2;
	n2->prev = n1;
	

	return n1;
}

t_stack_node *create_stacka()
{
	t_stack_node *n1 = create_node(1);
	t_stack_node *n2 = create_node(2);
	t_stack_node *n3 = create_node(3);
	t_stack_node *n4 = create_node(4);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n1;

	n1->prev = n4;
	n2->prev = n1;
	n3->prev = n2;
	n4->prev = n3;

	return n1;
}

t_stack_node *create_stackb()
{
	t_stack_node *n1 = create_node(5);
	t_stack_node *n2 = create_node(6);
	t_stack_node *n3 = create_node(7);
	t_stack_node *n4 = create_node(8);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n1;

	n1->prev = n4;
	n2->prev = n1;
	n3->prev = n2;
	n4->prev = n3;

	return n1;
}

int main(void)
{
	t_stack_node *a = create_short(); // Stack A with 4 nodes
	t_stack_node *b = NULL; // Stack B empty

	printf("\nSTARTING STATE:\n");
	print_stack(a, 'A');
	print_stack(b, 'B');
	printf("\n");
	
	sa(&a);
	printf("After sa:\n");
	print_stack(a, 'A');
	printf("\n");

	sa(&a);
	printf("After sa:\n");
	print_stack(a, 'A');
	printf("\n");

	a = create_stacka();

	pa(&a, &b);
	printf("After pa:\n");
	print_stack(a, 'A');
	print_stack(b, 'B');
	printf("\n");

	pb(&a, &b);
	printf("After pb:\n");
	print_stack(a, 'A');
	print_stack(b, 'B');
	printf("\n");

	pa(&a, &b);
	printf("After pa:\n");
	print_stack(a, 'A');
	print_stack(b, 'B');
	printf("\n");

	pb(&a, &b);
	printf("After pb:\n");
	print_stack(a, 'A');
	print_stack(b, 'B');
	printf("\n");

	pb(&a, &b);
	printf("After pb:\n");
	print_stack(a, 'A');
	print_stack(b, 'B');
	printf("\n");

	rr(&a, &b);
	printf("After rr:\n");
	print_stack(a, 'A');
	print_stack(b, 'B');

	ra(&a);
	printf("After ra:\n");
	print_stack(a, 'A');
	printf("\n");

	rb(&b);
	printf("After rb:\n");
	print_stack(b, 'B');
	printf("\n");

	rrr(&a, &b);
	printf("After rrr:\n");
	print_stack(a, 'A');
	print_stack(b, 'B');

	rra(&a);
	printf("After rra:\n");
	print_stack(a, 'A');
	printf("\n");

	rrb(&b);
	printf("After rrb:\n");
	print_stack(b, 'B');
	printf("\n");

	sa(&a);
	printf("After sa:\n");
	print_stack(a, 'A');
	printf("\n");

	sb(&b);
	printf("After sb:\n");
	print_stack(b, 'B');
	printf("\n");
	
	sa(&a);
	printf("After sa:\n");
	print_stack(a, 'A');
	printf("\n");

	sb(&b);
	printf("After sb:\n");
	print_stack(b, 'B');
	printf("\n");

	ss(&a, &b);
	printf("After ss:\n");
	print_stack(a, 'A');
	print_stack(b, 'B');

	printf("========================\n");
	printf("========================\n");
	
	b = create_stackb();
	a = create_stacka();

	printf("\nSTARTING STATE:\n");
	print_stack(a, 'A');
	print_stack(b, 'B');
	printf("\n");

	sa(&a);
	printf("After sa:\n");
	print_stack(a, 'A');
	printf("\n");

	sb(&b);
	printf("After sb:\n");
	print_stack(b, 'B');
	printf("\n");
	
	sa(&a);
	printf("After sa:\n");
	print_stack(a, 'A');
	printf("\n");

	sb(&b);
	printf("After sb:\n");
	print_stack(b, 'B');
	printf("\n");
	
	sa(&a);
	printf("After sa:\n");
	print_stack(a, 'A');
	printf("\n");

	sb(&b);
	printf("After sb:\n");
	print_stack(b, 'B');
	printf("\n");
	
	ss(&a, &b);
	printf("After ss:\n");
	print_stack(a, 'A');
	print_stack(b, 'B');
	printf("========================\n");
	printf("========================\n");

	printf("\nSTARTING STATE:\n");
	print_stack(a, 'A');
	print_stack(b, 'B');
	printf("\n");

	rra(&a);
	printf("After rra:\n");
	print_stack(a, 'A');
	printf("\n");

	rrb(&b);
	printf("After rrb:\n");
	print_stack(b, 'B');
	printf("\n");

	rrr(&a, &b);
	printf("After rrr:\n");
	print_stack(a, 'A');
	print_stack(b, 'B');

	printf("========================\n");
	printf("========================\n");

	printf("\nSTARTING STATE:\n");
	print_stack(a, 'A');
	print_stack(b, 'B');
	printf("\n");

	sa(&a);
	printf("After sa:\n");
	print_stack(a, 'A');
	printf("\n");

	sb(&b);
	printf("After sb:\n");
	print_stack(b, 'B');
	printf("\n");

	ss(&a, &b);
	printf("After ss:\n");
	print_stack(a, 'A');
	print_stack(b, 'B');
	printf("\n");

	printf("========================\n");
	printf("========================\n");

	printf("\nSTARTING STATE:\n");
	print_stack(a, 'A');
	print_stack(b, 'B');
	printf("\n");

	ra(&a);
	printf("After ra:\n");
	print_stack(a, 'A');
	printf("\n");

	rb(&b);
	printf("After rb:\n");
	print_stack(b, 'B');
	printf("\n");

	rr(&a, &b);
	printf("After rr:\n");
	print_stack(a, 'A');
	print_stack(b, 'B');

	printf("========================\n");
	printf("========================\n");

	printf("\nSTARTING STATE:\n");
	print_stack(a, 'A');
	print_stack(b, 'B');
	printf("\n");

	pa(&a, &b);
	printf("After pa:\n");
	print_stack(a, 'A');
	print_stack(b, 'B');
	printf("\n");

	pa(&a, &b);
	printf("After pa:\n");
	print_stack(a, 'A');
	print_stack(b, 'B');
	printf("\n");

	pa(&a, &b);
	printf("After pa:\n");
	print_stack(a, 'A');
	print_stack(b, 'B');
	printf("\n");

	pa(&a, &b);
	printf("After pa:\n");
	print_stack(a, 'A');
	print_stack(b, 'B');
	printf("\n");

	pb(&a, &b);
	printf("After pb:\n");
	print_stack(a, 'A');
	print_stack(b, 'B');
	printf("\n");

	pb(&a, &b);
	printf("After pb:\n");
	print_stack(a, 'A');
	print_stack(b, 'B');
	printf("\n");

	pb(&a, &b);
	printf("After pb:\n");
	print_stack(a, 'A');
	print_stack(b, 'B');
	printf("\n");

	pb(&a, &b);
	printf("After pb:\n");
	print_stack(a, 'A');
	print_stack(b, 'B');
	printf("\n");

	pb(&a, &b);
	printf("After pb:\n");
	print_stack(a, 'A');
	print_stack(b, 'B');
	printf("\n");

	pb(&a, &b);
	printf("After pb:\n");
	print_stack(a, 'A');
	print_stack(b, 'B');
	printf("\n");

	pb(&a, &b);
	printf("After pb:\n");
	print_stack(a, 'A');
	print_stack(b, 'B');
	printf("\n");

	pb(&a, &b);
	printf("After pb:\n");
	print_stack(a, 'A');
	print_stack(b, 'B');
	printf("\n");

	printf("========================\n");
	printf("========================\n");

	printf("\nSTARTING STATE:\n");
	print_stack(a, 'A');
	print_stack(b, 'B');
	printf("\n");


	rb(&b);
	printf("After rb:\n");
	print_stack(b, 'B');
	printf("\n");

	pa(&a, &b);
	printf("After pa:\n");
	print_stack(a, 'A');
	print_stack(b, 'B');
	printf("\n");

	rb(&b);
	printf("After rb:\n");
	print_stack(b, 'B');
	printf("\n");

	pa(&a, &b);
	printf("After pa:\n");
	print_stack(a, 'A');
	print_stack(b, 'B');
	printf("\n");

	
	rb(&b);
	printf("After rb:\n");
	print_stack(b, 'B');
	printf("\n");

	pa(&a, &b);
	printf("After pa:\n");
	print_stack(a, 'A');
	print_stack(b, 'B');
	printf("\n");

	
	rb(&b);
	printf("After rb:\n");
	print_stack(b, 'B');
	printf("\n");

	pa(&a, &b);
	printf("After pa:\n");
	print_stack(a, 'A');
	print_stack(b, 'B');
	printf("\n");
	

	printf("========================\n");
	printf("========================\n");

	return 0;
}

