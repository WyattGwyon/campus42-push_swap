/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_linked_lists.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouden <clouden@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:56:21 by clouden           #+#    #+#             */
/*   Updated: 2025/08/05 12:56:59 by clouden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*ft_dl_lstnew(int value)
{
	t_stack_node	*new;

	new = malloc(sizeof(t_stack_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

void	ft_dl_lstadd_front(t_stack_node **head, t_stack_node *new)
{
	if (!head || !new)
		return ;
	if (!*head)
	{
		new->next = new;
		new->prev = new;
		*head = new;
	}
	else
	{
		new->next = *head;
		new->prev = (*head)->prev;
		(*head)->prev->next = new;
		(*head)->prev = new;
		*head = new;
	}
}

void	ft_dl_lstdelhead(t_stack_node **head)
{
	t_stack_node	*old_head;

	if (!head || !*head)
		return ;
	old_head = *head;
	if (old_head->next == old_head)
	{
		free(old_head);
		*head = NULL;
		return ;
	}
	old_head->prev->next = old_head->next;
	old_head->next->prev = old_head->prev;
	*head = old_head->next;
	free(old_head);
	old_head = NULL;
}

void	ft_dl_lstclear(t_stack_node **head)
{
	if (!head || !*head)
		return ;
	while (*head)
	{
		ft_dl_lstdelhead(head);
	}
	*head = NULL;
}
