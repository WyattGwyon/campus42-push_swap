/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_dups_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouden <clouden@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 19:41:02 by clouden           #+#    #+#             */
/*   Updated: 2025/07/25 19:41:05 by clouden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

int check_dup()
{

}

int insert_hash(t_parse_struct *p, t_node *hash_table[TABLE_SIZE])
{
	unsigned long h_idx;
	t_node *new_node;
	int i;

	i = 0;
	new_node = malloc(sizeof(t_node));
	while (p->strarr[i])
	{
		h_idx = djb2(p->strarr[i]) % TABLE_SIZE;
		new_node->next = hash_table[h_idx];
		i++;
	}
}
