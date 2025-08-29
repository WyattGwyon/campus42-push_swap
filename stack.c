/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouden <clouden@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 21:33:19 by clouden           #+#    #+#             */
/*   Updated: 2025/08/04 21:33:25 by clouden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_indices(t_stack_node *head, int size)
{
	int				i;
	int				j;
	long int		min;
	t_stack_node	*min_node;
	t_stack_node	*current;

	i = 0;
	while (i < size)
	{
		min = INT_MAX;
		min_node = NULL;
		current = head;
		j = 0;
		while (size > j++)
		{
			if (current->index == -1 && current->value < (min + 1))
			{
				min = current->value;
				min_node = current;
			}
			current = current->next;
		}
		min_node->index = i++;
	}
}

t_stack_node	*stack_list(t_parser *p)
{
	int				i;
	t_stack_node	*new_node;
	t_stack_node	*head;

	i = p->len - 1;
	head = NULL;
	while (i >= 0)
	{
		new_node = ft_dl_lstnew(p->intarr[i]);
		new_node->index = -1;
		ft_dl_lstadd_front(&head, new_node);
		i--;
	}
	assign_indices(head, p->len);
	return (head);
}

void	stack_controller(t_parser *p)
{
	t_stack_node	*a_stack;
	t_stack_node	*b_stack;

	a_stack = stack_list(p);
	b_stack = NULL;
	if (p->len == 3)
		three_value_algo(&a_stack);
	else if (p->len == 5)
		five_value_algo(&a_stack, &b_stack);
	else
		radix_sort(&a_stack, &b_stack, p->len);
	ft_dl_lstclear(&a_stack);
	ft_dl_lstclear(&b_stack);
}
