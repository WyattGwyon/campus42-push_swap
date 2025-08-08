/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouden <clouden@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 17:38:25 by clouden           #+#    #+#             */
/*   Updated: 2025/08/06 17:38:34 by clouden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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