/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouden <clouden@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 22:17:47 by clouden           #+#    #+#             */
/*   Updated: 2025/07/22 22:18:12 by clouden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct s_stacks t_stacks;
typedef void (*t_operation)(t_stacks *s);

typedef struct	s_op_handler
{
	const char *name;
	t_operation op;
}	t_op_handler;


void init_handlers(t_op_handler *op_handlers);

# endif