/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouden <clouden@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 23:33:29 by clouden           #+#    #+#             */
/*   Updated: 2025/08/01 23:33:34 by clouden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_issorted(t_parser *p)
{
    int i;
    int cmp;

    i = 0;
    while ((i + 1) < p->len)
    {
        cmp = p->intarr[i] < p->intarr[i + 1];
        if (!cmp)
            return (printf("NOT sorted\n"), 0);
        i++;
    }
    return (printf("is sorted\n"),1);
}
