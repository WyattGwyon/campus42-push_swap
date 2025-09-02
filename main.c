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

//make exec ARG="$(echo $(shuf -i 1-100 -n 100))"
// or
// nmp start

void if_sorted(t_parser *data)
{
	if (ft_issorted(data))
	{
		ft_strarr_free(&data->strarr);
		free(data->intarr);
		data->intarr = NULL;
		free(data);
		exit(EXIT_SUCCESS);
	}
	else
		return ;
}

int	main(int argc, char **argv)
{
	t_parser		*data;

	if (argc < 2)
		return (0);
	data = parse_controller(argc, argv);
	if (!data)
		return (write(2, "Error\n", 6), 1);
	if (!data->intarr)
	{
		ft_strarr_free(&data->strarr);
		free(data);
		return (write(2, "Error\n", 6), 1);
	}
	if_sorted(data);
	stack_controller(data);
	ft_strarr_free(&data->strarr);
	free(data->intarr);
	data->intarr = NULL;
	free(data);
	return (0);
}
