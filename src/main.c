/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouden <clouden@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 22:40:12 by clouden           #+#    #+#             */
/*   Updated: 2025/07/15 22:45:12 by clouden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int main(int argc, char **argv)
{
	int	i;
	int *intarr;
	i = 1;

	if (argc < 2)
	{
		return (0);
	}
	if (argc == 2)
	{
		intarr = ft_str2ints(argv[1]);
		int len = ft_arrlen(&intarr);
		printf("len %d\n", len);
		if (!intarr)
		{
			printf("contains non-numerica info");
			return (0);
		}
	}
	while (i < argc)
	{
		printf("%s\n", argv[i]);
		i++;
	}
}