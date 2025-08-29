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

# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_parser
{
	char	**strarr;
	int		*intarr;
	int		len;
	int		max;
	int		min;
}	t_parser;

typedef struct s_stack_node
{
	int					value;
	int					index;
	struct s_stack_node	*prev;
	struct s_stack_node	*next;
}	t_stack_node;

t_parser		*parse_controller(int argc, char *argv[]);
int				ft_issorted(t_parser *p);
int				ft_isrevsorted(t_parser *p);
int				ft_lssorted(t_stack_node *head);
int				ft_lsrevsorted(t_stack_node *head);
t_stack_node	*stack_list(t_parser *p);
void			stack_controller(t_parser *p);
t_stack_node	*ft_dl_lstnew(int value);
void			ft_dl_lstadd_front(t_stack_node **head, t_stack_node *new);
void			ft_dl_lstdelhead(t_stack_node **head);
void			ft_dl_lstclear(t_stack_node **head);
void			ft_struct_free(void **ptr);
void			ft_intarr_free(int **arr);
void			clean_parser(t_parser **p);
void			clean_all(t_parser **p, t_stack_node **a_stack, \
							t_stack_node **b_stack);
void			push(t_stack_node **src_head, t_stack_node **dest_head);
void			swap(t_stack_node **head);
void			rotate(t_stack_node **head);
void			rev_rotate(t_stack_node **head);
void			radix_sort(t_stack_node **a, t_stack_node **b, int size);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **a, t_stack_node **b);
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);
void			three_value_algo(t_stack_node **a);
void			five_value_algo(t_stack_node **a, t_stack_node **b);

#endif