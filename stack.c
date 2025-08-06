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

static void	print_list(t_stack_node *head, int count)
{
	t_stack_node	*curr;
	int				i;

	curr = head;
	i = 0;
	while (i < count)
	{
		printf("%d ", curr->value);
		curr = curr->next;
		i++;
	}
	printf("\n");
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
		ft_dl_lstadd_front(&head, new_node);
		i--;
	}
	return (head);
}

void	stack_controller(t_parser *p)
{
	t_stack_node	*a_stack;
	t_stack_node	*b_stack;

	a_stack = stack_list(p);
	b_stack = NULL;
	print_list(a_stack, p->len);
	ft_dl_lstclear(&a_stack);
	ft_dl_lstclear(&b_stack);
}

