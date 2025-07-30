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

void ft_free_strarr(char ***arr)
{
	int i;

	if (!arr || !*arr)
		return;
	i = 0;
	while ((*arr)[i])
	{
		free((*arr)[i]);
		i++;
	}
	free(*arr);
	*arr = NULL;
}

int	ft_arrlen(char **arr)
{
	int len;

	len = 0;
	while (arr && arr[len])
		len++;
	return (len);
}

char **ft_strarr_join(char **arr1, char **arr2)
{
	char	**join;
	int		i;
	int		j;

	i = 0;
	j = 0;
	join = ft_calloc((ft_arrlen(arr1) + ft_arrlen(arr2)) + 1, sizeof(char*));
	if (!join)
		return (NULL);
	while (arr1 && arr1[i])
	{
		join[i] = ft_strdup(arr1[i]);
		if (!join[i])
			return (ft_free_strarr(&join), NULL);
		i++;
	}
	while (arr2 && arr2[j])
	{	
		join[i + j] = ft_strdup(arr2[j]);
		if (!join[i + j])
			return (ft_free_strarr(&join), NULL);
		j++;
	}
	return (join);
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
			return (ft_free_strarr(&strarr), NULL);
		joined = ft_strarr_join(strarr, split);
		ft_free_strarr(&split);
		ft_free_strarr(&strarr);
		if (!joined)
			return (NULL);
		strarr = joined;
		i++;
	}
	return (strarr);
}

t_parser *parse_controller(int argc, char *argv[])
{
	int i;
	t_parser *p_data;

	
	if (argc < 2)
		return (NULL);
	p_data = ft_calloc(1, sizeof(t_parser));
	p_data->strarr = arg_separation(argc, argv);
	if(!p_data->strarr)
	{
		free(p_data);
		return (NULL);
	}
	i = 0;
	while (p_data->strarr[i])
	{
		printf("srtarr[%d] %s\n", i, p_data->strarr[i]);
		i++;
	}
	return (p_data);
}
