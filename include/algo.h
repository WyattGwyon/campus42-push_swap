/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouden <clouden@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 22:15:59 by clouden           #+#    #+#             */
/*   Updated: 2025/07/24 22:16:02 by clouden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H
# define TABLE_SIZE 1009 // a prime number for better distribution

# include "parser.h"

typedef struct s_node {
    char *str;
    struct s_node *next;
} t_node;

unsigned long djb2(const char *str);
int insert_hash(t_parse_struct *p, t_node *hash_table[TABLE_SIZE]);

#endif