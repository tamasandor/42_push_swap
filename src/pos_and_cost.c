/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_and_cost.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atamas <atamas@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 23:00:34 by atamas            #+#    #+#             */
/*   Updated: 2024/03/25 19:06:17 by atamas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <limits.h>

void	current_pos(t_stack **stack_a)
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
}

static int	get_lowest(t_stack **stack_a, int b_index, int target_index,
					int target_position)
{
	t_stack	*temp_a;

	temp_a = *stack_a;
	while (temp_a)
	{
		if (temp_a->index > b_index && temp_a->index < target_index)
		{
			target_index = temp_a->index;
			target_position = temp_a->pos;
		}
		temp_a = temp_a->next;
	}
	if (target_index != INT_MAX)
		return (target_position);
	temp_a = *stack_a;
	while (temp_a)
	{
		if (temp_a->index < target_index)
		{
			target_index = temp_a->index;
			target_position = temp_a->pos;
		}
		temp_a = temp_a->next;
	}
	return (target_position);
}

void	target(t_stack **a, t_stack **b)
{
	t_stack	*temp_b;
	int		t_position;

	current_pos(a);
	current_pos(b);
	t_position = -1;
	temp_b = *b;
	while (temp_b)
	{
		t_position = get_lowest(a, temp_b->index, INT_MAX, t_position);
		temp_b->target_pos = t_position;
		temp_b = temp_b->next;
	}
}

void	cost(t_stack *stack_b, int size_a, int size_b)
{
	t_stack	*temp_b;

	temp_b = stack_b;
	while (temp_b)
	{
		temp_b->cost_b = temp_b->pos;
		if (temp_b->pos > size_b / 2)
			temp_b->cost_b = (size_b - temp_b->pos) * -1;
		temp_b->cost_a = temp_b->target_pos;
		if (temp_b->target_pos > size_a / 2)
			temp_b->cost_a = (size_a - temp_b->target_pos) * -1;
		temp_b = temp_b->next;
	}
}
