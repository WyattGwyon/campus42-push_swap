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

t_stack *stack_creation(t_parser *p)
{
	t_stack *s;

	s->a_stack = p->intarr;
	s->a_stack = ft_calloc(p->len, sizeof(int));
	if (!s->a_stack)
		return (NULL);
	ft_memcpy(s->a_stack, p->intarr, p->len * sizeof(int));
	s->b_stack = ft_calloc(p->len, sizeof(int));
	s->a_top = 0;
	s->b_top = 0;
	s->len = p->len;
	return (s);
}
