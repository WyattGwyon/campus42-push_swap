/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouden <clouden@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 20:42:36 by clouden           #+#    #+#             */
/*   Updated: 2025/08/12 20:42:45 by clouden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_value_algo(t_stack_node **a)
{
	int *head;
	int *next;
	int *prev;

	head = (*a)->index;
	next = (*a)->next->index;
	prev = (*a)->prev->index;
	if ((head > next && head > prev) && next < prev)
	{
		ra(&a);
		return ;
	}
	if ((head < next && head > prev) && next > prev)
	{
		sa(&a);
		rra(&a);
		return ;
	}
	if (!ft_issorted(a) && (head < next && head < prev))
	{
		sa(&a);
		ra(&a);
		return ;
	}
	if (head > prev && head < next)
	{
		rra(&a);
		return ;
	}
	if (head < prev && head > next)
	{
		sa(&a);
		return ;
	}

}


void	five_value_algo(t_stack_node *a, t_stack_node *b)
{
	pb(&a, &b);
	pb(&a, &b);

}