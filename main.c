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

#include "push_swap.h"

void free_strarr(char ***strarr) 
{
    int i;


	i = 0;
	if (!strarr || !*strarr)
        return;
	while ((*strarr)[i])
	{
		free((*strarr)[i]);
		(*strarr)[i] = NULL;
		i++;
	}
    free(*strarr);
    *strarr = NULL;
}

int main(int argc, char **argv)
{
	t_parser 	*data;
	t_stack		*stack;

	data = parse_controller(argc, argv);
	if (!data)
		return (write(2,"Error\n", 6), 1);
	if (!data->intarr)
	{
		free_strarr(&data->strarr);
		free(data);
		return (write(2, "Error\n", 6), 1);
	}
	stack = stack_creation(data);

	free_strarr(&data->strarr);
	free(data->intarr);
	data->intarr = NULL;
	free(data);

	
	return (0);
}
