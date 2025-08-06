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

static void	print_list(t_stack_node *head, int count)
{
	t_stack_node	*curr;
	int				i;

	curr = head;
	i = 0;
	while (i < count)
	{
		printf("%d ", curr->value);
		curr = curr->next;
		i++;
	}
	printf("\n");
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
	ft_issorted(data);
	stack_controller(data);
	ft_strarr_free(&data->strarr);
	free(data->intarr);
	data->intarr = NULL;
	free(data);
	return (0);
}
