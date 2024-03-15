/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamas <atamas@stundent.42wolfsburg.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:34:13 by atamas            #+#    #+#             */
/*   Updated: 2024/03/15 15:52:00 by atamas           ###   ########.fr       */
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