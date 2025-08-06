/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouden <clouden@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 17:40:24 by clouden           #+#    #+#             */
/*   Updated: 2025/08/06 17:40:29 by clouden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
