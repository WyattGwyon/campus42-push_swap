/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouden <clouden@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:25:14 by clouden           #+#    #+#             */
/*   Updated: 2025/07/16 16:25:23 by clouden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft.h"
# include <stdio.h>

typedef struct s_parse
{
	int *intarr;
	int i;
	size_t size;
} t_parse_struct;

// int ft_arrlen(void *arr);
// int *parse_str2ints(char *str);
// int *ft_isintset(int *arr);
int *parse_controller(int argc, char *argv[], t_parse_struct *parse);

#endif