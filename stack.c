/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouden <clouden@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 21:33:19 by clouden           #+#    #+#             */
/*   Updated: 2025/08/04 21:33:25 by clouden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*stack_list(t_parser *p)
{
	int				i;
	t_stack_node	*new_node;
	t_stack_node	*head;

	i = p->len - 1;
	head = NULL;
	while (i >= 0)
	{
		new_node = ft_dl_lstnew(p->intarr[i]);
		ft_dl_lstadd_front(&head, new_node);
		i--;
	}
	return (head);
}



// #include <stdio.h>
// #include <stdlib.h>
// #include <assert.h>

// // Assume t_stack_node and your list functions are declared

// // Helper: print the list (for debugging)
// void print_list(t_stack_node *head, int count) {
//     t_stack_node *curr = head;
//     for (int i = 0; i < count; i++) {
//         printf("%d ", curr->value);
//         curr = curr->next;
//     }
//     printf("\n");
// }

// // Test function for stack_list
// void test_stack_list() {
//     // Setup parser with example data
//     t_parser p;
//     int arr[] = {10, 20, 30, 40};
//     p.intarr = arr;
//     p.len = 4;

//     // Call the function
//     t_stack_node *head = stack_list(&p);

//     // Verify list length and values (should be 10 -> 20 -> 30 -> 40)
//     t_stack_node *curr = head;
//     for (int i = 0; i < p.len; i++) {
//         assert(curr != NULL);
//         assert(curr->value == arr[i]);
//         curr = curr->next;
//     }

//     // Optionally print list for manual check
//     print_list(head, p.len);

//     // Clean up list
//     ft_dl_lstclear(&head);
//     assert(head == NULL);

//     printf("test_stack_list passed!\n");
// }

// int main() {
//     test_stack_list();
//     return 0;
// }
