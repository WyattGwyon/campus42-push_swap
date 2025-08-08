/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouden <clouden@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 16:38:14 by clouden           #+#    #+#             */
/*   Updated: 2025/08/08 16:38:18 by clouden          ###   ########.fr       */
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

t_stack_node *create_stack()
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

int main(void)
{
	t_stack_node *a = create_stack(); // Stack A with 4 nodes
	t_stack_node *b = NULL;           // Stack B empty

	printf("Before pa:\n");
	print_stack(a, 'A');
	print_stack(b, 'B');

	pb(&a, &b); // Move top of A to B

	printf("\nAfter pb:\n");
	print_stack(a, 'A');
	print_stack(b, 'B');

	pa(&a, &b); // Move top of B back to A

	printf("\nAfter pa:\n");
	print_stack(a, 'A');
	print_stack(b, 'B');

	pb(&a, &b); // Move top of A to B

	printf("\nAfter pb:\n");
	print_stack(a, 'A');
	print_stack(b, 'B');

	pb(&a, &b); // Move top of A to B

	printf("\nAfter pb:\n");
	print_stack(a, 'A');
	print_stack(b, 'B');


	return 0;
}