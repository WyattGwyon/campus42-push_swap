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

// void    radix_sort(t_stack_node **a, t_stack_node **b, int size)
// {
//     int max_bits;
//     int i;
//     int j;

//     i = 0;
//     max_bits = get_max_bits(size - 1);
//     while (i < max_bits)
//     {
//         j = 0;
//         while (j < size)
//         {
//             if ((((*a)->index >> i) & 1) == 0)
//                 pb(a,b);
//             else
//                 ra(a);
//             j++;
//         }
//         while (*b)
//             pa(a,b);
//         i++;
//     }
// }

void	radix_sort(t_stack_node **a, t_stack_node **b, int size)
{
	int	max_bits;
	int	i;
	int	j;
	int pbs;
	int pas;
	int a_rem;
	int b_rem;
    int pb;

	i = 0;
	a_rem = size;
	b_rem = 0;
    pas = 0;
    pbs = 0;
    pb = 0;
	max_bits = get_max_bits(size - 1);
	while (i != max_bits + 1)
	{
		j = 0;
		while (j < pbs)
		{
            if ((((*a)->index >> i) & 1) == 0)
			{
				pb(a, b);   
				pb++;
			}
			else
				ra(a);
			j++;
		}
        if (ft_lssorted(*a) && ft_lsrevsorted(*b))
        {
            while (*b)
                pa(a,b);
            return ;
        }
        pbs = 0;
        while (j < a_rem)
		{
			if ((((*a)->index >> i) & 1) == 0)
			{
				pb(a, b);   
				pbs++;
			}
			else
				ra(a);
			j++;
		}
		i++;

		// if (i == max_bits + 1)
		// 	return ;

		j = 0;
		b_rem = b_rem + pbs - pas;
        pas = 0;
		while (j < b_rem)
		{	
			if ((((*b)->index >> i) & 1) == 1)
			{
				pa(a, b);
				pas++;
			}
			else
				rb(b);
			j++;
		}
		a_rem = a_rem + pas - pbs;
	}
    return ;
}
