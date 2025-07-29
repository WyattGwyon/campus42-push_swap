/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouden <clouden@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:06:48 by clouden           #+#    #+#             */
/*   Updated: 2025/07/16 19:06:54 by clouden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int *parse_controller(int argc, char *argv[], t_parse_struct *p)
{
	int i;
	// t_node *hash_table[TABLE_SIZE];

	if (argc < 2)
		return (NULL);
	if (argc == 2)
		p->strarr = ft_split(argv[1], ' ');
	else
        p->strarr = &argv[1];
	if(!p->strarr)
		return (NULL);
	i = 0;
	while (p->strarr[i])
	{
		printf("srtarr[%d] %s\n", i, p->strarr[i]);
		i++;
	}

	return (NULL);
}
