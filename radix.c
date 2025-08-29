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

int	radix_pre_a(t_stack_node **a, t_stack_node **b, t_radix *r)
{
	r->j = 0;
	while (r->j < r->pas)
	{
		ra(a);
		r->j++;
	}
	if (ft_lssorted(*a) && ft_lsrevsorted(*b))
	{
		while (*b)
			pa(a, b);
		return (1);
	}
	return (0);
}

int	radix_a(t_stack_node **a, t_stack_node **b, t_radix *r)
{
	r->pbs = 0;
	while (r->j < r->a_rem)
	{
		if ((((*a)->index >> r->i) & 1) == 0)
		{
			pb(a, b);
			r->pbs++;
		}
		else
			ra(a);
		if (ft_lssorted(*a) && ft_lsrevsorted(*b))
		{
			while (*b)
				pa(a, b);
			return (1);
		}
		r->j++;
	}
	return (0);
}

int	radix_b(t_stack_node **a, t_stack_node **b, t_radix *r)
{
	r->pas = 0;
	while (r->j < r->b_rem)
	{
		if ((((*b)->index >> r->i) & 1) == 1)
		{
			pa(a, b);
			r->pas++;
		}
		else
			rb(b);
		if (ft_lssorted(*a) && ft_lsrevsorted(*b))
		{
			while (*b)
				pa(a, b);
			return (1);
		}
		r->j++;
	}
	return (0);
}

void	radix_sort(t_stack_node **a, t_stack_node **b, int size)
{
	t_radix	r;

	r.i = 0;
	r.pas = 0;
	r.pbs = 0;
	r.a_rem = size;
	r.b_rem = 0;
	r.max_bits = get_max_bits(size - 1);
	while (r.i < r.max_bits)
	{
		if (radix_pre_a(a, b, &r) == 1)
			return ;
		if (radix_a(a, b, &r) == 1)
			return ;
		r.i++;
		r.j = 0;
		r.b_rem = r.b_rem + r.pbs - r.pas;
		if (radix_b(a, b, &r) == 1)
			return ;
		r.a_rem = r.a_rem + r.pas - r.pbs;
	}
}
