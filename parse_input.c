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

#include "push_swap.h"

static int contains_dup(t_parser *p)
{
	int head;
	int cmp;

	head = 0;
	cmp = 1;
	while (head < p->len)
	{
		while (cmp < p->len)
		{
			if (p->intarr[head] == p->intarr[cmp])
				return (1);
			cmp++;
		}
		head++;
		cmp = head + 1;
	}
	return (0);
}

static int	valid_number(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (i == 0 && (str[i] == '+' || str[i] == '-'))
				i++;
		if (ft_isdigit(str[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}

static char **arg_separation(int argc, char *argv[])
{
	int i;
	char **strarr;
	char **split;
	char **joined;

	i = 1;
	joined = NULL;
	strarr = NULL;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			return (ft_strarr_free(&strarr), NULL);
		joined = ft_strarr_join(strarr, split);
		ft_strarr_free(&split);
		ft_strarr_free(&strarr);
		if (!joined)
			return (NULL);
		strarr = joined;
		i++;
	}
	return (strarr);
}

static int *digit_manager(t_parser *p)
{
	int i;
	long val;

	i = 0;
	p->len = ft_strarr_len(p->strarr);
	p->intarr = ft_calloc(p->len + 1, sizeof(int));
	if (!p->intarr)
		return (NULL);
	while (i < p->len)
	{
		if (!valid_number(p->strarr[i]))
			return(NULL);
		else
		{
			val = ft_atol(p->strarr[i]);
			if (val > INT_MAX || val < INT_MIN)
				return (NULL);
			p->intarr[i] = val;
		}
		i++;
	}
	return (p->intarr);
}

// need to dispose of data here
t_parser *parse_controller(int argc, char *argv[])
{
	int i;
	t_parser *p_data;

	if (argc < 2)
		return (NULL);
	p_data = ft_calloc(1, sizeof(t_parser));
	p_data->strarr = arg_separation(argc, argv);
	if(!p_data->strarr)
		return (NULL);
	p_data->intarr = digit_manager(p_data);
	if (!p_data->intarr)
		return (NULL);
	if (contains_dup(p_data))
		return (NULL);
	if (ft_issorted(p_data))
		return (p_data);
	i = 0;
	while (p_data->strarr[i])
	{
		printf("srtarr[%d] %s\n",   i, p_data->strarr[i]);
		printf("intarr[%d] %d\n\n", i, p_data->intarr[i]);
		i++;
	}
	printf("len %d\n", p_data->len);

	return (p_data);
}
