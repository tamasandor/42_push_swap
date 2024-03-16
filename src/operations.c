/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamas <atamas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:34:13 by atamas            #+#    #+#             */
/*   Updated: 2024/03/16 15:47:13 by atamas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <unistd.h>

void	push_to_x(t_stack **from, t_stack **to, char *txt)
{
	t_stack	*temp_a;
	t_stack	*temp_b;

	if (*from)
	{
		temp_a = *from;
		temp_b = temp_a->next;
		temp_a->next = *to;
		*from = temp_b;
		*to = temp_a;
		if (txt)
			write(1, txt, 3);
	}
}

void	swap_x(t_stack **stack, char *txt)
{
	t_stack	*original;
	t_stack	*temp;

	original = *stack;
	if (*stack && original->next)
	{
		temp = original->next;
		original->next = original->next->next;
		temp->next = original;
		*stack = temp;
		if (txt)
			write(1, txt, 3);
	}
}

void	rotate_x(t_stack **stack, char *txt)
{
	t_stack	*node_that_we_move;
	t_stack	*temp;

	temp = *stack;
	if (temp && temp->next)
	{
		node_that_we_move = temp;
		*stack = temp->next;
		while (temp->next)
			temp = temp->next;
		temp->next = node_that_we_move;
		node_that_we_move->next = NULL;
		if (txt)
			write(1, txt, 3);
	}
}

void	reverse_rotate_x(t_stack **stack, char *txt)
{
	t_stack	*second_to_last;
	t_stack	*last_node;

	last_node = *stack;
	if (last_node && last_node->next)
	{
		while (last_node->next)
		{
			second_to_last = last_node;
			last_node = last_node->next;
		}
		if (second_to_last)
			second_to_last->next = NULL;
		last_node->next = *stack;
		*stack = last_node;
		if (txt)
			write(1, txt, 4);
	}
}

/* 
multiple_operation function handles the operations when you have to do multiple
operations
1: ss = swap a and swap b
2: rr = rotate a and rotate b
3: rrr = reverse rotate a and reverse rotate b
 */
void	multiple_operation(t_stack **stack_a, t_stack **stack_b, int op)
{
	if (op == 1)
	{
		swap_x(stack_a, NULL);
		swap_x(stack_b, "ss\n");
	}
	else if (op == 2)
	{
		rotate_x(stack_a, NULL);
		rotate_x(stack_b, "rr\n");
	}
	else if (op == 3)
	{
		reverse_rotate_x(stack_a, NULL);
		reverse_rotate_x(stack_b, "rrr\n");
	}
}
