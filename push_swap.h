/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouden <clouden@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 16:25:14 by clouden           #+#    #+#             */
/*   Updated: 2025/07/16 16:25:23 by clouden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define TABLE_SIZE 1009 // a prime number for better distribution

# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_parser
{
	char	**strarr;
	int		*intarr;
	int		len;
}	t_parser;

typedef struct s_stack_node
{
	int					value;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}	t_stack_node;

typedef struct s_stack
{
	int	*a_stack;
	int	*b_stack;
	int	a_top;
	int	b_top;
	int	len;
}	t_stack;

typedef struct s_node
{
	char			*str;
	struct s_node	*next;
}	t_node;

typedef struct s_hash_table
{
	t_node	*index[TABLE_SIZE];
}				t_hash_table;

typedef struct s_stacks	t_stacks;
typedef void			(*t_operation)(t_stacks *s);

typedef struct s_op_handler
{
	const char	*name;
	t_operation	op;
}	t_op_handler;

void			init_handlers(t_op_handler *op_handlers);
unsigned long	djb2(const char *str);
t_parser		*parse_controller(int argc, char *argv[]);
int				ft_issorted(t_parser *p);
t_stack_node	*stack_list(t_parser *p);
t_stack_node	*ft_dl_lstnew(int value);
void			ft_dl_lstadd_front(t_stack_node **head, t_stack_node *new);
void			ft_dl_lstdelhead(t_stack_node **head);
void			ft_dl_lstclear(t_stack_node **head);
void			ft_struct_free(void **ptr);
void			ft_intarr_free(int **arr);
void			clean_parser(t_parser **p);
void			clean_all(t_parser **p, t_stack_node **a_stack, t_stack_node **b_stack);
void			push(t_stack_node **src_head, t_stack_node **dest_head);
void			swap(t_stack_node **head);
void			rotate(t_stack_node **head, char direction);

// int ft_arrlen(void *arr);
// int *parse_str2ints(char *str);
// int *ft_isintset(int *arr);
// int insert_hash(t_parse_struct *p, t_node *hash_table[TABLE_SIZE]);

#endif