/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouden <clouden@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 22:15:14 by clouden           #+#    #+#             */
/*   Updated: 2025/07/22 22:15:18 by clouden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void pa(t_stacks *s)
void pb(t_stacks *s)
void sa(t_stacks *s)

void init_handlers(t_op_handler *op_handlers)
{
	handlers[0] = (t_handler){"pa", pa};
	handlers[1] = (t_handler){"pd", pb};
	handlers[2] = (t_handler){"sa", sa};
}