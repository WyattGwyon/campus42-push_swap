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

void	push(t_stack_node **src_head, t_stack_node **dest_head)
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
		*dest_head = push_node;
		push_node->next = push_node;
		push_node->prev = push_node;
	}
	else
	{
		push_node->next = *dest_head;
		push_node->prev = (*dest_head)->prev;
		(*dest_head)->prev = push_node;
		(*dest_head)->prev->next = push_node;
		*dest_head = push_node;
	}
}
