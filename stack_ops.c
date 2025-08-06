/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouden <clouden@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 22:15:14 by clouden           #+#    #+#             */
/*   Updated: 2025/07/22 22:15:18 by clouden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void pa(t_stacks *s)
// void pb(t_stacks *s)
// void sa(t_stacks *s)

// void init_handlers(t_op_handler *op_handlers)
// {
// 	handlers[0] = (t_handler){"pa", pa};
// 	handlers[1] = (t_handler){"pd", pb};
// 	handlers[2] = (t_handler){"sa", sa};
// }

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

void	swap(t_stack_node **head)
{
	(*head)->prev->next = (*head)->next;
	(*head)->next->next->prev = *head;
	(*head)->next->prev = (*head)->prev;
	(*head)->prev = (*head)->next;
	(*head)->next = (*head)->next->next;
	(*head)->prev->next = *head;
	*head = (*head)->prev;
}

void	rotate(t_stack_node **head)
{
	*head = (*head)->prev;
}
		
void	reverse_rotate(t_stack_node **head)
{
	*head = (*head)->next;
}