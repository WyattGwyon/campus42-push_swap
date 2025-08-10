/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouden <clouden@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 15:58:04 by clouden           #+#    #+#             */
/*   Updated: 2025/08/06 15:58:06 by clouden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_intarr_free(int **arr)
{
	if (arr && *arr)
	{
		free(*arr);
		*arr = NULL;
	}
}

void	ft_struct_free(void **ptr)
{
	if (ptr && *ptr)
	{
		free(ptr);
		*ptr = NULL;
	}
}

void	clean_parser(t_parser **p)
{
	printf("are we free");
	if ((*p)->strarr)
		ft_strarr_free(&(*p)->strarr);
	if ((*p)->intarr)
		ft_intarr_free(&(*p)->intarr);
	ft_struct_free((void **)p);
}

void	clean_all(t_parser **p, t_stack_node **a_stack, t_stack_node **b_stack)
{
	if (p && *p)
	{
		ft_strarr_free(&(*p)->strarr);
		ft_intarr_free(&(*p)->intarr);
		ft_struct_free((void **)p);
	}
	if (a_stack && *a_stack)
		ft_dl_lstclear(&(*a_stack));
	if (b_stack && *b_stack)
		ft_dl_lstclear(&(*b_stack));
}
