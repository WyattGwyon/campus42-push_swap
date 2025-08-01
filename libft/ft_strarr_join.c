/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarr_join.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouden <clouden@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 19:18:18 by clouden           #+#    #+#             */
/*   Updated: 2025/08/01 19:18:41 by clouden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char **ft_strarr_join(char **arr1, char **arr2)
{
	char	**join;
	int		i;
	int		j;

	i = 0;
	j = 0;
	join = ft_calloc((ft_strarr_len(arr1) + ft_strarr_len(arr2)) + 1, sizeof(char*));
	if (!join)
		return (NULL);
	while (arr1 && arr1[i])
	{
		join[i] = ft_strdup(arr1[i]);
		if (!join[i])
			return (ft_strarr_free(&join), NULL);
		i++;
	}
	while (arr2 && arr2[j])
	{	
		join[i + j] = ft_strdup(arr2[j]);
		if (!join[i + j])
			return (ft_strarr_free(&join), NULL);
		j++;
	}
	return (join);
}
