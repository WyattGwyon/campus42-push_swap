/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_djb2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouden <clouden@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 22:26:39 by clouden           #+#    #+#             */
/*   Updated: 2025/07/24 22:36:56 by clouden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"

unsigned long djb2(const char *str)
{
	unsigned long hash = 5381;
	int c;

	while (1)
	{
		c = *str;
		if (c == '\0')
			break;
		hash = ((hash << 5) + hash) + c;
		str++;
	}
	return (hash);
}

