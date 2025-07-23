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

// This will get the number of elements in the array
// int ft_arrlen(void *arr)
// {
//     int len;

//     len = 0;
//     while (arr)
//     {
//         len++;
//         arr++;
//     }
//     return (len);
// }

// This will parse a string of space separated digits
// and return a pointer to an array of ints


// int *parse_str2ints(char *str)
// {
//     char **strarr;
//     int *intarr;
//     int len;
//     int i;

//     i = 0;
//     while (str[i])
//     {
//         if (ft_isdigit(str[i]) == 0 && str[i] != ' ')
//             return(0);
//         i++;
//     }
//     i = 0;
//     strarr = ft_split(str, ' ');
//     len = ft_arrlen(strarr);
//     intarr = ft_calloc(len + 1, sizeof(int));
//     while (strarr[i])
//     {
//         intarr[i] = ft_atoi(strarr[i]);
//         printf("%d\n", intarr[i]);
//         i++;
//     }
//     return (intarr);
// }

// This function takes an array of ints
// and returns 1 if it contains duplicate values
// int *ft_isintset(int *arr)
// {
//     int i;
//     int j;
//     int len;

//     i = 0;
//     len = ft_arrlen(arr);
//     while (i < len)
//     {   
//         j = 0;
//         while (j < len)
//         {
//             if (i != j && arr[i] == arr[j])
//             {
//                 printf("we found a dup");
//                 return (1);
//             }
//             j++;
//         }
//         i++;
//     }
//     return (0);
// }

int *parse_ints(int argc, char *argv[], t_parse_struct *parse)
{
	parse->i = 1;
	parse->intarr = ft_calloc(argc - 1, sizeof(int));
	if (!parse->intarr)
		return (NULL);
	while (parse->i < argc)
	{
		if (ft_isdigit(*argv[parse->i]) == 1)
		{
			parse->intarr[parse->i-1] = ft_atoi(argv[parse->i]);
		}
		else
			return (printf("there was a letter\n"), NULL);
		printf("intarr[%d] %d\n", parse->i-1, parse->intarr[parse->i-1]);
		parse->i++;
	}
	return (parse->intarr);
}


int *parse_controller(int argc, char *argv[], t_parse_struct *parse)
{
	parse->i = 0;
	if (argc < 2)
		return (NULL);
	if (argc == 2)
	{
		printf("we have to split\n");
		return (0);
	}
	parse->intarr = parse_ints(argc, argv, parse);
	if (!parse->intarr)
		return (NULL);

	return (parse->intarr);
}
