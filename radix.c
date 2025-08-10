/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouden <clouden@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 18:53:07 by clouden           #+#    #+#             */
/*   Updated: 2025/08/10 22:10:08 by clouden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(int size)
{
	int	max;
	int	bits;

	max = size;
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_stack_node **a, t_stack_node **b, int size)
{
	int	max_bits;
	int	i;
	int	j;

	i = 0;
	max_bits = get_max_bits(size - 1);
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			// if (!(*a))
			// {
			//	 printf("Stack A is empty");
			// }
			if ((((*a)->index >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
			j++;
		}
		while (*b)
			pa(a, b);
		i++;
	}
}
