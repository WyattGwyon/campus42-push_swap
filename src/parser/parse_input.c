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

char **parse_args(int argc, char *argv[], t_parse_struct *p)
{
	int i;

	p->len = argc;
	p->strarr = ft_calloc(p->len, sizeof(char *));
	if (!p->strarr)
		return (NULL);
	i = 1;
	while (i < p->len)
	{
		p->strarr[i - 1] = ft_strdup(argv[i]);
		if (!p->strarr[i - 1])
		{
			while (i > 0)
			{
				free(p->strarr[i - 1]);
				i--;
			}
			free(p->strarr);
			return (NULL);
		}
		i++;
	}
	return (p->strarr);
}

int *parse_controller(int argc, char *argv[], t_parse_struct *p)
{
	int i;

	if (argc < 2)
		return (NULL);
	if (argc == 2)
		p->strarr = ft_split(argv[1], ' ', p);
	else
		p->strarr = parse_args(argc, argv, p);
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
