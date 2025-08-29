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
	int	head;
	int	next;
	int	prev;

	head = (*a)->index;
	next = (*a)->next->index;
	prev = (*a)->prev->index;
	if (head < next && next > prev && head > prev)
		rra(a);
	else if (head > next && next < prev && head > prev)
		ra(a);
	else if (head < next && next > prev && head < prev)
	{
		sa(a);
		ra(a);
	}
	else if (head > next && next < prev && head < prev)
		sa(a);
	else if (head > next && next > prev && head > prev)
	{
		sa(a);
		rra(a);
	}
	return ;
}

void	five_value_algo(t_stack_node **a, t_stack_node **b)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if ((*a)->index == 3 || (*a)->index == 4)
		{
			pb(a, b);
		}
		else
			ra(a);
		i++;
	}
	three_value_algo(a);
	if ((*b)->index == 3)
		sb(b);
	pa(a, b);
	pa(a, b);
	ra(a);
	ra(a);
}
