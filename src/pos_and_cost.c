/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_and_cost.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamas <atamas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 23:00:34 by atamas            #+#    #+#             */
/*   Updated: 2024/03/18 23:15:32 by atamas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	current_pos(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current;
	int		pos;

	current = *stack_a;
	pos = 0;
	while (current)
	{
		current->pos = pos++;
		current = current->next;
	}
	current = *stack_b;
	pos = 0;
	while (current)
	{
		current->pos = pos++;
		current = current->next;
	}
}